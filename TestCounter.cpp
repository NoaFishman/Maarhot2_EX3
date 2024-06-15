/*
ID: 319055430
Email: noa.fishman@gmail.com
*/
#define DOCTEST_CONFIG_IMPLEMENT
#include "doctest.h"
#include "catan.hpp"
using namespace doctest;

const int MIN_TESTS = 20;

int return_code = -1;
// this class is the main class of te tests that call the test functins and tell how many test i did and if i did less then 20

struct ReporterCounter : public ConsoleReporter
{
    ReporterCounter(const ContextOptions &input_options)
        : ConsoleReporter(input_options) {}

    void test_run_end(const TestRunStats &run_stats) override
    {
        std::cout << "you have " << run_stats.numAsserts << " tests" << std::endl;
        if (run_stats.numAsserts >= MIN_TESTS)
        {
            return_code = 0;
        }
        else
        {
            std::cout << "Please write at least " << MIN_TESTS << " tests! " << std::endl;
            return_code = 1;
        }
    }
};

REGISTER_REPORTER("counter", 1, ReporterCounter);

int main()
{
    Context context;
    context.addFilter("reporters", "counter");
    context.run();
    return return_code;
}