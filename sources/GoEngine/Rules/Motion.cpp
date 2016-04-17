#include "Motion.h"

Motion::Motion()
{
    moveIndex = 0;
    //TODO разобраться с автоматическим расширение вектора!
    moves.resize(movesSize);
}

void Motion::putStone(Board* board, int first, int second)
{
    ifNeedResizeMoves();
    ifMoveIllegalThrowException( board, first, second );
    board->operator()(first, second) = whoseMove();
    moves[moveIndex].putFirst(first);
    moves[moveIndex].putSecond(second);
    ++moveIndex;
}

void Motion::pass() noexcept
{
    ifNeedResizeMoves();
    moves[moveIndex].putFirst(0);
    moves[moveIndex].putSecond(0);
    ++moveIndex;
}

bool Motion::areTwoPasses() const noexcept
{
    Moves passedMove;
    passedMove.putFirst(0);
    passedMove.putSecond(0);
    return moves[moveIndex] == passedMove && moves[moveIndex] == moves[moveIndex-2];
}

int Motion::getMoveIndex() const noexcept
{
    return moveIndex;
}

vector<Moves>& Motion::getMoves() const noexcept
{
    return const_cast<vector<Moves>&>(moves);
}

void Motion::ifNeedResizeMoves() noexcept
{
    if( movesSize - 1 == moveIndex )
    {
        movesSize += 100;
        moves.resize(movesSize);
    }
}

bool Motion::isBlacksMove() const noexcept
{
    return !(moveIndex % 2);
}

int Motion::whoseMove() const noexcept
{
    if( isBlacksMove() )
    {
        return BLACK;
    }
    else
    {
        return WHITE;
    }
}

void Motion::ifMoveToNotEmptyPointThrowException( Board* board, int first, int second ) const
{
    if( board->operator()(first, second).isNotEmpty() )
    {
        throw MoveToNotEmptyPointException();
    }
}

void Motion::ifMoveRepeatThrowException( Board* board, int first, int second ) const
{
    //TODO fix bug
    if( moveIndex >= 2 )
    {
        Moves passedMove(0, 0);
        if( moves[moveIndex] != passedMove && moves[moveIndex] == moves[moveIndex-2] )
        {
            throw MoveRepeatException();
        }
    }
}

void Motion::ifMoveToDieThrowException( Board* board, int first, int second ) const
{
    //TODO void Motion::ifMoveToDie
    if( false )
    {
        throw MoveToDieException();
    }
}

void Motion::ifMoveIllegalThrowException( Board* board, int first, int second ) const
{
    ifMoveToNotEmptyPointThrowException(board, first, second);
    ifMoveRepeatThrowException(board, first, second);
    ifMoveToDieThrowException(board, first, second);
}
