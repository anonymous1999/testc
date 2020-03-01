
#include "gmock/gmock.h"
#include "gtest/gtest.h"

using namespace std;


class FooInterface
{
	public:
	virtual string getArbitraryString(const string & inputstring)
	{
		return string("TEST");
	};
};

class MockFoo: public FooInterface {
public:
        MOCK_METHOD0(getArbitraryString, std::string());
};

using ::testing::Return;

int main(int argc, char** argv) {
        ::testing::InitGoogleMock(&argc, argv);

        string value = "Hello World!";
        MockFoo mockFoo;
        EXPECT_CALL(mockFoo, getArbitraryString()).Times(1).
                WillOnce(Return(value));
        string returnValue = mockFoo.getArbitraryString();
        cout << "Returned Value: " << returnValue << endl;

        return 0;
}