#include "Year.h"

bool Year::is_valid(){
  if (year>min && year<max) return true;
  return false;
}
