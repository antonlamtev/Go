#ifndef GO_API_H
#define GO_API_H

namespace Go {

class API {
 public:
//void setBoardSize(const BoardSize &boardSize);
  void startGame();
//void makeAMove(const Move &move);
//PlayerColor whoseMove() const noexcept;
//Moves getMoves() const noexcept;
  void undo();
  void redo();
};

}
#endif //GO_API_H
