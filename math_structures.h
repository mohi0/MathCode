// file for defining math structures 

typedef struct HeaderCol {
  Cell *cell;
  HeaderfCol *nextHeader;
} HeaderCol;

typedef struct Cell {
  Cell *nextInCol;
  void *data;
} Cell;

typedef struct Row {
  
} Row;

typedef struct Table {
  HeaderCol *start;
} Table;

//initialise a new table
Table newTable(){
}


// add a column to table
void addCol(Table &table){
}

// add a row to table
void addRow(){
}

// remove a column from table
void removeCol(){
}

// remove a row from the table
void removeRow(){
}

//get column data from some index range or entire column
void getColData(){
}

//get entire row data from some index range or entire row
void getRowData(){
}
