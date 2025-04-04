public class Matrix{

  private final int rows;
  private final int columns;
  private int [][] mat;

  public Matrix(int rows, int columns){
    assert rows >= 0 && columns >= 0;
    this.rows = rows;
    this.columns = columns;
    mat = new int[this.rows][ this.columns];
  }

  public int getElemen(int row, int column){
    assert row<=this.rows && row >= 0;
    assert column<=this.columns && column >= 0;
    return mat[row][column];
  }

  public void setElement(int row, int column, int value){
    assert row<=this.rows && row >= 0;
    assert column<=this.columns && column >= 0;
    mat[row][column] = value;
  }

}