#include <gtest/gtest.h>
#include "monitor.h"

TEST(Monitor, TemperatureOutOfRange) {
    ASSERT_FALSE(vitalsOk(94.9, 70, 95));
    ASSERT_FALSE(vitalsOk(102.1, 70, 95));
}

TEST(Monitor, PulseRateOutOfRange) {
    ASSERT_FALSE(vitalsOk(98, 59, 95));
    ASSERT_FALSE(vitalsOk(98, 101, 95));
}

TEST(Monitor, Spo2OutOfRange) {
    ASSERT_FALSE(vitalsOk(98, 70, 89));
}

TEST(Monitor, AllVitalsOk) {
    ASSERT_TRUE(vitalsOk(98.6, 70, 95));
}

TEST(Monitor, BoundaryValues) {
    ASSERT_TRUE(vitalsOk(95, 60, 90));
    ASSERT_TRUE(vitalsOk(102, 100, 90));
}

