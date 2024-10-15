// file for defining math structures 

typedef struct HeaderCol {
  Cell *cell;
  HeaderfCol *nextHeader;
} HeaderCol;

typedef struct Cell {
  Cell *nextInCol;
  Void *data;
} Cell;

typedef struct Table {
  HeaderCol *start;
} Table;
