#include <unity.h>
#include "../src/BurpStatus.hpp"
#include "Status.hpp"

namespace Status {

    BurpStatus::Status status;

    Module tests("Status", [](Describe & d) {

        d.describe("with level INFO and code ok", [](Describe & d) {

            d.before([]() {
                status.set(BurpStatus::Status::Level::INFO, BurpStatus::Status::ok);
            });

            d.it("should have the correct level", []() {
                TEST_ASSERT_EQUAL(BurpStatus::Status::Level::INFO, status.getLevel());
            });

            d.it("should have the correct code", []() {
                TEST_ASSERT_EQUAL(BurpStatus::Status::ok, status.getCode());
            });

            d.it("should have the correct string representation", []() {
                TEST_ASSERT_EQUAL_STRING("BurpStatus::Status : ok", status.c_str());
            });

        });

        d.describe("with level ERROR and an unknown code", [](Describe & d) {

            d.before([]() {
                status.set(BurpStatus::Status::Level::ERROR, 100);
            });

            d.it("should have the correct level", []() {
                TEST_ASSERT_EQUAL(BurpStatus::Status::Level::ERROR, status.getLevel());
            });

            d.it("should have the correct code", []() {
                TEST_ASSERT_EQUAL(100, status.getCode());
            });

            d.it("should have the correct string representation", []() {
                TEST_ASSERT_EQUAL_STRING("BurpStatus::Status : unknown status", status.c_str());
            });

        });
    });

}