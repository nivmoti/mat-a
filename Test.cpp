/**
 * An example of how to write unit tests.
 * Use this as a basis to build a more complete Test.cpp file.
 * 
 * IMPORTANT: Please write more tests - the tests here are only for example and are not complete.
 *
 * AUTHORS: <Please write your names here>
 * 
 * Date: 2021-02
 */

#include "doctest.h"
#include "mat.hpp"
using namespace ariel;

#include <string>
#include <algorithm>
using namespace std;

/**
 * Returns the input string without the whitespace characters: space, newline and tab.
 * Requires std=c++2a.
 */
string nospaces(string input) {
	std::erase(input, ' ');
	std::erase(input, '\t');
	std::erase(input, '\n');
	std::erase(input, '\r');
	return input;
}


TEST_CASE("Good input") {
	CHECK(nospaces(mat(9, 7, '@', '-')) == nospaces("@@@@@@@@@\n"
													 "@-------@\n"
													 "@-@@@@@-@\n"
													 "@-@---@-@\n"
													 "@-@@@@@-@\n"
													 "@-------@\n"
													 "@@@@@@@@@"));
	/* Add more test here */
	CHECK(nospaces(mat(9, 7, '&', '^')) == nospaces("&&&&&&&&&\n"
													 "&^^^^^^^&\n"
													 "&^&&&&&^&\n"
													 "&^&^^^&^&\n"
													 "&^&&&&&^&\n"
													 "&^^^^^^^&\n"
													 "&&&&&&&&&"));


	CHECK(nospaces(mat(1, 5, '@', '-')) == nospaces("@\n"
													 "@\n"
													 "-\n"
													 "@\n"
													 "@\n"));

    
	CHECK(nospaces(mat(9, 1, '@', '-')) == nospaces("@@@@-@@@@\n"
													 ));


	CHECK(nospaces(mat(11, 13, '@', '-')) == nospaces("@@@@@@@@@@@\n"
	                                                  "@---------@\n"
													  "@-@@@@@@@-@\n"
													  "@-@-----@-@\n"
													  "@-@-@@@-@-@\n"
													  "@-@-@-@-@-@\n"
													  "@-@-@-@-@-@\n"
													  "@-@-@-@-@-@\n"
													  "@-@-@@@-@-@\n"
													  "@-@-----@-@\n"
													  "@-@@@@@@@-@\n"
													  "@---------@\n"
													  "@@@@@@@@@@@"));
	CHECK(nospaces(mat(13,11,'@','-'))==nospaces("@@@@@@@@@@@@@\n"
                                                 "@-----------@\n"
                                                 "@-@@@@@@@@@-@\n"
                                                 "@-@-------@-@\n"
                                                 "@-@-@@@@@-@-@\n"
                                                 "@-@-@---@-@-@\n"
                                                 "@-@-@@@@@-@-@\n"
                                                 "@-@-------@-@\n"
                                                 "@-@@@@@@@@@-@\n"
                                                 "@-----------@\n"
                                                 "@@@@@@@@@@@@@"));

    CHECK(nospaces(mat(1, 1, '@', '-')) == nospaces("@\n"
													 ));
    CHECK(nospaces(mat(1, 3, '@', '-')) == nospaces("@-@\n"
													 ));
    CHECK(nospaces(mat(3, 1, '@', '-')) == nospaces("@\n"
	                                                "-\n"
													"@"));
    CHECK(nospaces(mat(5, 5, '@', '-')) == nospaces("@@@@@\n"
	                                                "@---@\n"
													"@-@-@\n"
													"@---@\n"
													"@@@@@"
													 ));
    CHECK(nospaces(mat(5, 5, '@', '@')) == nospaces("@@@@@\n"
	                                                "@@@@@\n"
													"@@@@@\n"
													"@@@@@\n"
													"@@@@@"
													 ));
}

TEST_CASE("Bad input") {
    CHECK_THROWS(mat(10, 5, '$', '%'));
	CHECK_THROWS(mat(0, 5, '$', '%'));
    /* Add more test here */
	CHECK_THROWS(mat(10, 0, '$', '%'));
	CHECK_THROWS(mat(0, 0, '$', '%'));
	CHECK_THROWS(mat(1000000, 2, '$', '%'));
	CHECK_THROWS(mat(4, 20000001, '$', '%'));
	CHECK_THROWS(mat(2, 2, '$', '%'));
	CHECK_THROWS(mat(10, 10, '$', '%'));
	CHECK_THROWS(mat(-5, 10, '$', '%'));
	CHECK_THROWS(mat(10, -2, '$', '%'));
	CHECK_THROWS(mat(10, 10, '\0', '%'));
	CHECK_THROWS(mat(10, 10, '@', '\0'));

}


/* Add more test cases here */
