LAI 03;
STA A0;

LAI 05;
MBA;
LDA A1;
ADD;
STA A1;

LAI 01;
MBA;
LDA A0;
SUB;
STA A0;

JN 0F;
JMP 02;
HLT;