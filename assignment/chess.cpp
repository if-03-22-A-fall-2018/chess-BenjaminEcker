/*----------------------------------------------------------
 *				HTBLA-Leonding / Klasse: 2AHDV
 * ---------------------------------------------------------
 * Exercise Number: 0
 * Title:			chess.c
 * Author:			P. Bauer
 * Due Date:		November 03, 2010
 * ----------------------------------------------------------
 * Description:
 * Implementation of basic chess functions.
 * ----------------------------------------------------------
 */
 /*#include <stdlib.h>
 #include "general.h"*/
 #include "chess.h"

 bool 	is_piece (struct ChessPiece pc, enum PieceColor color, enum PieceType type)
 {
   if ((pc.color==color)&&(pc.type==type))
   {
     return true;
   }
   return false;
 }
 void 	init_chess_board (ChessBoard chess_board)
 {
    for(int i=0;i<=8;i++)
    {
      for (int j = 0; j <= 8; j++)
      {
        chess_board[j][i].is_occupied=false;
      }
    }
 }
 struct ChessSquare * 	get_square (ChessBoard chess_board, File file, Rank rank)
 {
   if (rank < 1 || rank >8 || file < 'a' || file > 'h')
   {
     return 0;
   }
   else
   {
     return &chess_board[rank-1][file-'a'];
   }
 }
 bool 	is_square_occupied (ChessBoard chess_board, File file, Rank rank)
 {
   if(chess_board[rank-1][file-'a'].is_occupied)
   {
     return true;
   }
   return false;
 }
 bool 	add_piece (ChessBoard chess_board, File file, Rank rank, struct ChessPiece piece)
 {
   if((chess_board[rank-1][file-'a'].is_occupied==true)||rank < 1 || rank >8 || file < 'a' || file > 'h')
   {
     return false;
   }
   else
   {
    chess_board[rank-1][file-'a'].piece=piece;
   chess_board[rank-1][file-'a'].is_occupied=true;
   return true;
   }
 }
 struct ChessPiece 	get_piece (ChessBoard chess_board, File file, Rank rank)
 {
   struct ChessPiece piece;
   if (rank < 1 || rank >8 || file < 'a' || file > 'h' || chess_board[rank-'A'][file-'A'].is_occupied==true)
   {
      piece.type = NoPiece;
      return piece;
   }
    return chess_board[rank-1][file-'a'].piece;
 }

 void 	setup_chess_board (ChessBoard chess_board)
 {
    init_chess_board(chess_board);
    struct ChessPiece white_rook = {White, Rook};
    struct ChessPiece white_knight = {White, Knight};
    struct ChessPiece white_bishop = {White, Bishop};
    struct ChessPiece white_queen = {White, Queen};
    struct ChessPiece white_king = {White, King};
    struct ChessPiece white_pawn ={White, Pawn};

    add_piece(chess_board, 'a', 1, white_rook);
    add_piece(chess_board, 'b', 1, white_knight);
    add_piece(chess_board, 'c', 1, white_bishop);
    add_piece(chess_board, 'd', 1, white_queen);
    add_piece(chess_board, 'e', 1, white_king);
    add_piece(chess_board, 'f', 1, white_bishop);
    add_piece(chess_board, 'g', 1, white_knight);
    add_piece(chess_board, 'h', 1, white_rook);

    for (char i = 'a'; i <= 'h'; i++)
    {
      add_piece(chess_board, i, 2, white_pawn);
    }

    struct ChessPiece black_rook = {Black, Rook};
    struct ChessPiece black_knight = {Black, Knight};
    struct ChessPiece black_bishop = {Black, Bishop};
    struct ChessPiece black_queen = {Black, Queen};
    struct ChessPiece black_king = {Black, King};
    struct ChessPiece black_pawn ={Black, Pawn};

    add_piece(chess_board, 'a', 8, black_rook);
    add_piece(chess_board, 'b', 8, black_knight);
    add_piece(chess_board, 'c', 8, black_bishop);
    add_piece(chess_board, 'd', 8, black_queen);
    add_piece(chess_board, 'e', 8, black_king);
    add_piece(chess_board, 'f', 8, black_bishop);
    add_piece(chess_board, 'g', 8, black_knight);
    add_piece(chess_board, 'h', 8, black_rook);

    for (char i = 'a'; i <= 'h'; i++)
    {
      add_piece(chess_board, i, 7, black_pawn);
    }

    for (int i = 3; i < 6; i++)
    {
      for (int j = 0; j< 8; j++)
      {
       chess_board[i][j].is_occupied = false;
      }
    }
}
 bool 	remove_piece (ChessBoard chess_board, File file, Rank rank)
 {
   if((chess_board[rank-'A'][file-'A'].is_occupied==true)||(rank < 1 || rank >8 || file < 'a' || file > 'h'))
   {
     chess_board[rank-'A'][file-'A'].is_occupied=false;
     chess_board[rank -1][file-'a'].piece.type = NoPiece;
     return true;
   }
   return false;
 }
 bool 	squares_share_file (File s1_f, Rank s1_r, File s2_f, Rank s2_r)
 {
   return false;
 }
 bool 	squares_share_rank (File s1_f, Rank s1_r, File s2_f, Rank s2_r)
 {
   return false;
 }
 bool 	squares_share_diagonal (File s1_f, Rank s1_r, File s2_f, Rank s2_r)
 {
   return false;
 }
 bool 	squares_share_knights_move (File s1_f, Rank s1_r, File s2_f, Rank s2_r)
 {
   return false;
 }
 bool 	squares_share_pawns_move (enum PieceColor color, enum MoveType move, File s1_f, Rank s1_r, File s2_f, Rank s2_r)
 {
   return false;
 }
 bool 	squares_share_queens_move (File s1_f, Rank s1_r, File s2_f, Rank s2_r)
 {
   return false;
 }
 bool 	squares_share_kings_move (File s1_f, Rank s1_r, File s2_f, Rank s2_r)
 {
   return false;
 }
