#ifndef TEMPOS_H
#define TEMPOS_H

#define SEMIBREVE 1
#define MINIMA 2
#define SEMIMINIMA 4
#define COLCHEIA 8
#define SEMICOLCHEIA 16
#define FUSA 32
#define SEMIFUSA 64

enum tempo {
  SEMIBREVE    = SEMIBREVE ,
  MINIMA       = MINIMA ,
  SEMIMINIMA   = SEMIMINIMA ,
  COLCHEIA     = COLCHEIA ,
  SEMICOLCHEIA = SEMICOLCHEIA ,
  FUSA         = FUSA ,
  SEMIFUSA     = SEMIFUSA  
};

#endif /* TEMPOS_H */