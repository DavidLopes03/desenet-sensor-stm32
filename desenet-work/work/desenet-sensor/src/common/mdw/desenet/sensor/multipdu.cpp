#include "multipdu.h"
#include <cstring>

#include "multipdu.h"
#include <cstring>
#include "platform-config.h"

/**
 * @brief MultiPDU::MultiPDU
 */
MultiPDU::MultiPDU() : Frame(Frame::Mtu), _ePDUCount(0), _currentDataByteIdx(EMPTY_DATA_LENGTH){

    // Cache the buffer start address for direct access
    _bufferStartAddr = buffer();

    // define destination adress (set in platform-config.h)
    setDestination(GATEWAY_ADDRESS);

    // set frame type to multi pdu frame
    // -> Set multi PDU headers bit 7 to one
    setType(FrameType::MPDU);

    // Set initial frame length to the minimum size (Frame Header + MPDU Header + Footer)
    setLength(Frame::HEADER_SIZE + EMPTY_DATA_LENGTH + Frame::FOOTER_SIZE);
}

/**
 * @brief MultiPDU::reset : resets the multi pdu frame for a new sending
 * @param sensorId
 */
void MultiPDU::reset(uint8_t sensorId){

    _ePDUCount = 0; // reste edpu count
    _currentDataByteIdx = EMPTY_DATA_LENGTH; // reset data start index

    // define destination adress (set in platform-config.h)
    setDestination(GATEWAY_ADDRESS);

    // add sensor ID to multi PDUs header
    uint8_t header = sensorId & 0x7F; //keeps the MSB (bit 7) for frame type

    // write sensor ID in the buffer
    // -> Write after the frames header (jumps 5 bytes)
    _bufferStartAddr[Frame::HEADER_SIZE] = header;

    // set frame type to multi pdu frame
    // -> Set multi PDU headers bit 7 to one
    setType(FrameType::MPDU);

    // Add edpu couter after frames and multi PDU headers (5 + 1 baytes)
    // edpu couter init value = 0, so byte 6 of buffer is 0
    _bufferStartAddr[Frame::HEADER_SIZE + 1] = _ePDUCount;

    // Set initial frame length to the minimum size (Frame Header + MPDU Header + Footer)
    setLength(Frame::HEADER_SIZE + EMPTY_DATA_LENGTH + Frame::FOOTER_SIZE);
}

/**
 * @brief MultiPDU::addSvEPDU : add an Sampled Value to the multi pdu frame
 * @param group
 * @param data
 * @param length
 */
void MultiPDU::addSvEPDU(uint8_t group, const uint8_t * data, uint8_t length){

    // construct the sv header
    // bit 7 = 0
    // bit 3..6 = sv group
    // bit 0..2 = sv data lenght
    uint8_t Svheader = (0 << 7) | ((group & 0x0F) << 3) | (length & 0x07);

    // Add sv header to current index
    // At start: index = 5 + 2 bytes (prevents erasing frame header, multi PDU header, and ePDU count)
    _bufferStartAddr[Frame::HEADER_SIZE + _currentDataByteIdx] = Svheader;
    _currentDataByteIdx++; // increase current index for additional sv or ev

    // Add sv data bytes right after sv header (current index increased by one)
    memcpy(_bufferStartAddr + Frame::HEADER_SIZE + _currentDataByteIdx, data, length);
    _currentDataByteIdx += length; // increase curent writable index by data lenght just added

    //increas eDPU counter
    _ePDUCount++;
}

/**
 * @brief MultiPDU::addEvEPDU : add an event to the multi pdu frame
 * @param eventId
 * @param data
 * @param length
 */
void MultiPDU::addEvEPDU(uint8_t eventId, const uint8_t * data, uint8_t length){

    // check if its not enought space to add a new ev
    if (_currentDataByteIdx + 1 + length > Frame::Mtu - Frame::HEADER_SIZE - Frame::FOOTER_SIZE) {
        return; // ignore new ev ePDU
    }

    // construct the ev header
    // bit 7 = 1
    // bit 3..6 = ev id
    // bit 0..2 = ev data lenght
    uint8_t header = (1 << 7) | ((eventId & 0x0F) << 3) | (length & 0x07);

    // Add ev header to current index
    // At start: index = 5 + 2 bytes (prevents erasing frame header, multi PDU header, and ePDU count)
    _bufferStartAddr[Frame::HEADER_SIZE + _currentDataByteIdx] = header;
    _currentDataByteIdx++;

    // Add ev data bytes right after  ev header (current index increased by one)
    memcpy(_bufferStartAddr + Frame::HEADER_SIZE + _currentDataByteIdx, data, length);
    _currentDataByteIdx += length; // increase curent writable index by data lenght just added

    //increas eDPU counter
    _ePDUCount++;
}

/**
 * @brief MultiPDU::finalize
 */
void MultiPDU::finalize(){

    // Update the ePDU count field (2nd byte of payload) with the final number of items added
    _bufferStartAddr[Frame::HEADER_SIZE + 1] = _ePDUCount;

    // Update the total frame length to reflect the actual data written
    // Total = Frame Header (5) + Actual Payload Data (_currentDataByteIdx) + Footer
    setLength(Frame::HEADER_SIZE + _currentDataByteIdx + Frame::FOOTER_SIZE);
}
