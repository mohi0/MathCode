// file for defining math structures 

typedef struct HeaderCol {
  Cell *cell;
  HeaderfCol *nextHeader;
} HeaderCol;

typedef struct Cell {
  Cell *nextInCol;
  void *data;
} Cell;

typedef struct Table {
  HeaderCol *start;
} Table;

//initialise a new table
void newTable(){
}


// add a column to table
void addCol(){
}

// add a row to table
void addRow(){
}

// remove a column ffrom table
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
