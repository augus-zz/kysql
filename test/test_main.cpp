#include <QApplication>

#include "test_helper.h"

int main(int argc, char** argv)
{
  QApplication app(argc, argv);

  INCLUDE_ALL_TESTS(argc, argv)

  ::testing::InitGoogleTest(&argc, argv);
  RUN_ALL_TESTS();
}
