#ifndef TEST_CONNECTION_MANAGER_H
#define TEST_CONNECTION_MANAGER_H

#include "../../test_helper.h"


#include "../../../src/utils/connection_manager.h"

namespace
{

class TestConnectionManager : public ::testing::Test
{
protected:
  TestConnectionManager();
  virtual ~TestConnectionManager();

  virtual void SetUp();
  virtual void TearDown();
};

}


#endif
