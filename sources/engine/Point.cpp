#include "Point.h"

namespace Go {

Point::Point(PointLocation location, PointStatus status) noexcept
    : location{location},
      status{status} { }

PointLocation Point::getLocation() const noexcept {
  return location;
}

PointStatus Point::getStatus() const noexcept {
  return status;
}

Stone Point::getStone() const {
  if (status == PointStatus::EMPTY) {
    throw StoneNotFoundException{};
  }
  return *stone;
}

void Point::addStone(const Stone &stone) noexcept {
  this->stone = std::make_unique<Stone>(stone);
  status = static_cast<PointStatus>(stone.getColor());
}

void Point::deleteStone() noexcept {
  stone.reset();
  status = PointStatus::EMPTY;
}

}