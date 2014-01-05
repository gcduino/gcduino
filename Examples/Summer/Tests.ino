#include <ArduinoUnit.h>
#include "Utils.h"

test(uvZero) 
{
  assertEqual(eightBitToUVIndex(0), 0);
  assertEqual(eightBitToUVIndex(9), 0);
  assertEqual(eightBitToUVIndex(45), 0);
}

test(uvOne) 
{
  assertEqual(eightBitToUVIndex(46), 1);
  assertEqual(eightBitToUVIndex(64), 1);
}

test(uvTwo) 
{
  assertEqual(eightBitToUVIndex(65), 2);
  assertEqual(eightBitToUVIndex(82), 2);
}

test(uvThree) 
{
  assertEqual(eightBitToUVIndex(83), 3);
  assertEqual(eightBitToUVIndex(102), 3);
}

test(uvFour) 
{
  assertEqual(eightBitToUVIndex(103), 4);
  assertEqual(eightBitToUVIndex(123), 4);
}

test(uvFive) 
{
  assertEqual(eightBitToUVIndex(124), 5);
  assertEqual(eightBitToUVIndex(141), 5);
}

test(uvSix) 
{
  assertEqual(eightBitToUVIndex(142), 6);
  assertEqual(eightBitToUVIndex(161), 6);
}

test(uvSeven) 
{
  assertEqual(eightBitToUVIndex(162), 7);
  assertEqual(eightBitToUVIndex(179), 7);
}

test(uvEight) 
{
  assertEqual(eightBitToUVIndex(180), 8);
  assertEqual(eightBitToUVIndex(199), 8);
}

test(uvNine) 
{
  assertEqual(eightBitToUVIndex(200), 9);
  assertEqual(eightBitToUVIndex(220), 9);
}

test(uvTen) 
{
  assertEqual(eightBitToUVIndex(221), 10);
  assertEqual(eightBitToUVIndex(239), 10);
}

test(uvEleven) 
{
  assertEqual(eightBitToUVIndex(240), 11);
  assertEqual(eightBitToUVIndex(241), 11);
  assertEqual(eightBitToUVIndex(255), 11);
}

