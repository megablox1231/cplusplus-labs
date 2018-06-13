// L.A.18.1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "apmatrix.h"

int main()
{
    return 0;
}

//package Life;
//
//import java.io.File;
//import java.util.Scanner;
//
//public class Grid {
//
//	private String[][] myMatrix;
//
//	public Grid() {
//		initMatrix();
//		loadFile();
//	}
//
//	private void initMatrix() {
//		myMatrix = new String[20][20];
//		for (int row = 0; row < 20; row++) {
//			for (int col = 0; col < 20; col++) {
//				myMatrix[row][col] = " ";
//			}
//		}
//	}
//
//	private void loadFile() {
//		try {
//			Scanner scan = new Scanner(new File("life100.txt"));
//			while (scan.hasNext()) {
//				int row = scan.nextInt();
//				int col = scan.nextInt();
//				myMatrix[row - 1][col - 1] = "*";
//			}
//		}
//		catch (Exception e) {
//			System.out.print(e);
//		}
//	}
//
//	//Simulates one generation of cell deaths and births
//	public void generation() {
//		String[][] copy = new String[20][20];
//		for (int row = 0; row < 20; row++) {
//			for (int col = 0; col < 20; col++) {
//				copy[row][col] = myMatrix[row][col];
//			}
//		}
//		for (int row = 0; row < 20; row++) {
//			for (int col = 0; col < 20; col++) {
//				decide(row, col, copy);
//			}
//		}
//	}
//	//decides whether a cell lives or dies
//	private void decide(int row, int col, String[][] copy) {
//		int neighbors = 0;
//		for (int i = row - 1; i <= row + 1; i++) {
//			if (i > -1 && i < 20) {
//				for (int j = col - 1; j <= col + 1; j++) {
//					if (j > -1 && j < 20 && (j != col || i != row) && copy[i][j].equals("*"))
//						neighbors++;
//				}
//			}
//		}
//		if (copy[row][col].equals("*")) {
//			if (neighbors < 2 || neighbors > 3)
//				myMatrix[row][col] = " ";
//		}
//		else if (copy[row][col].equals(" ")) {
//			if (neighbors == 3)
//				myMatrix[row][col] = "*";
//		}
//	}
//
//	//displays how the grid looks at a generation
//	public void display() {
//		System.out.println("  12345678901234567890");
//		for (int row = 0; row < 20; row++) {
//			System.out.print(row + 1);
//			if (row < 9)
//				System.out.print(" ");
//			for (int col = 0; col < 20; col++) {
//				System.out.print(myMatrix[row][col]);
//			}
//			System.out.println();
//		}
//	}
//
//	//counts living cells in a row
//	public int getRowCells(int row) {
//		int alive = 0;
//		for (int cell = 0; cell < 20; cell++) {
//			if (myMatrix[row][cell].equals("*"))
//				alive++;
//		}
//		return alive;
//	}
//
//	//counts living cells in a column
//	public int getColCells(int col) {
//		int alive = 0;
//		for (int cell = 0; cell < 20; cell++) {
//			if (myMatrix[cell][col].equals("*"))
//				alive++;
//		}
//		return alive;
//	}
//
//	//counts living cells in the grid
//	public int getCells() {
//		int alive = 0;
//		for (int row = 0; row < 20; row++) {
//			for (int col = 0; col < 20; col++) {
//				if (myMatrix[row][col].equals("*"))
//					alive++;
//			}
//		}
//		return alive;
//	}
//	public static void main(String[] cheese) {
//		Grid grid = new Grid();
//		for (int i = 0; i < 5; i++) {
//			grid.generation();
//		}
//		grid.display();
//		System.out.println("Number in Row 10 ---> " + grid.getRowCells(9));
//		System.out.println("Number in Column 10 ---> " + grid.getColCells(9));
//		System.out.println("Number of Living Organisms ---> " + grid.getCells());
//	}
//}
