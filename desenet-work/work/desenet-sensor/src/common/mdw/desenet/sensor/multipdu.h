#ifndef MULTIPDU_H
#define MULTIPDU_H

#include <cstdint>
#include <cstddef>
#include "desenet/frame.h"

class MultiPDU : public desenet::Frame {
public:
    MultiPDU();
    ~MultiPDU() = default;

    void reset(uint8_t sensorId);
    void addSvEPDU(uint8_t group, const uint8_t * data, uint8_t length);
    void addEvEPDU(uint8_t eventId, const uint8_t * data, uint8_t length);
    void finalize();

private:
    static constexpr uint8_t EMPTY_DATA_LENGTH = 2;  // Frame type/sensor ID + ePDU count
    uint8_t _ePDUCount;
    size_t _currentDataByteIdx;
    uint8_t * _bufferStartAddr;
};

#endif // MULTIPDU_H
