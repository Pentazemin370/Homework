
/* ========================================================================
   datapath.h: skeleton project file for CS355

   Use this file to write the DataPath circuit component of Pj6
   ======================================================================== */

void DataPath( const SD &coord,
	       const Signal &mir, const Signal &mbr, 
	       const Signal &Phase, const Signal &Reset, 
	       const Signal &R0, const Signal &R1, const Signal &R2, 
	       const Signal &R3, const Signal &R4, const Signal &R5, 
	       const Signal &R6, const Signal &R7, const Signal &R8, 
	       const Signal &R9, const Signal &R10, const Signal &R11, 
	       const Signal &R12, const Signal &R13, const Signal &R14, 
	       const Signal &R15, const Signal &ABus, const Signal &BBus, 
	       const Signal &ALatch, const Signal &BLatch,
	       const Signal &AMux, const Signal &ALU, const Signal &CBus, 
	       const Signal &N, const Signal &Z 
              )
{
   Module( coord, "DataPath", 
           (mir, mbr, Phase, Reset), 
           (R0, R1, R2, R3, R4, R5, R6, R7, R8, R9, 
	    R10, R11, R12, R13, R14, R15, 
	    ABus, BBus, ALatch, BLatch, AMux, ALU, CBus, N, Z)
         );
SigV(init0,16,0b0000000000000000);
SigV(initR6,16,0b0000000000000001);
SigV(initR7,16,0b1111111111111111);

Sig(A, 16);
Sig(B, 16);
Sig(c, 16);
Sig(r0,16);
Sig(r1,16);
Sig(r2,16);
Sig(r3,16);
Sig(r4,16);
Sig(r5,16);
Sig(r6,16);
Sig(r7,16);
Sig(r8,16);
Sig(r9,16);
Sig(r10,16);
Sig(r11,16);
Sig(r12,16);
Sig(r13,16);
Sig(r14,16);
Sig(r15,16);
Signal n_reset;
Signal c1 , c0, out;
Signal inputR7;

//Or(SD(coord, "aa"), (Addr[0], Addr[3]), inputR7);

Sig(instr, 9);
//And(SD(coord,"aa"), 
Signal not_amux;

Not(SD(coord,"aa"), Reset, n_reset);
Not(SD(coord, "aa"), mir[31], not_amux);
Decoder(SD(coord,"aa"),not_amux ,(mir[11],mir[10],mir[9],mir[8]), A);
Decoder(SD(coord,"aa"),not_amux, (mir[15],mir[14],mir[13],mir[12]),B);
Decoder(SD(coord,"aa"), mir[20],(mir[19],mir[18],mir[17],mir[16]), c);




ResetableReg16(SD(coord,"aa"), r0, Phase[2], Reset, R0);



Reg16(SD(coord,"aa"), r1, Phase[2], R1);
Reg16(SD(coord,"aa"), r2, Phase[2], R2);
Reg16(SD(coord,"aa"), r3, Phase[2], R3);
Reg16(SD(coord,"aa"), r4, Phase[2], R4);
Constant16(SD(coord,"aa"), 0b0000000000000001,R6);
Constant16(SD(coord,"aa"),0b1111111111111111,R7);
Constant16(SD(coord,"aa"), 0b0000000000000000,R5);
Reg16(SD(coord,"aa"), r8, Phase[2], R8);
Reg16(SD(coord,"aa"), r9, Phase[2], R9);
Reg16(SD(coord,"aa"), r10, Phase[2], R10);
Reg16(SD(coord,"aa"), r11, Phase[2], R11);
Reg16(SD(coord,"aa"), r12, Phase[2], R12);
Reg16(SD(coord,"aa"), r13, Phase[2], R13);
Reg16(SD(coord,"aa"), r14, Phase[2], R14);
Reg16(SD(coord,"aa"), r15, Phase[2], R15);
/*
//Reg16(SD(coord,"aa"), AMux, Phase[1], ALU);
*/

Sig(d,16);
And(SD(coord,"aa"), (Phase[1],c[0]), d[0]);
And(SD(coord,"aa"), (Phase[1],c[1]), d[1]);
And(SD(coord,"aa"), (Phase[1],c[2]), d[2]);
And(SD(coord,"aa"), c[3], d[3]);
And(SD(coord,"aa"), c[4], d[4]);
And(SD(coord,"aa"), c[5], d[5]);
And(SD(coord,"aa"), c[6], d[6]);
And(SD(coord,"aa"), c[7], d[7]);
And(SD(coord,"aa"), c[8], d[8]);
And(SD(coord,"aa"), c[9], d[9]);
And(SD(coord,"aa"), c[10], d[10]);
And(SD(coord,"aa"), c[11], d[11]);
And(SD(coord,"aa"), c[12], d[12]);
And(SD(coord,"aa"), c[13], d[13]);
And(SD(coord,"aa"), c[14], d[14]);
/*
ResetableReg16(SD(coord,"aa"), CBus, c[0],Phase[3], r0);
ResetableReg16(SD(coord,"aa"), CBus, c[1],Phase[3], r1);
ResetableReg16(SD(coord,"aa"), CBus, c[2],Phase[3], r2);
ResetableReg16(SD(coord,"aa"), CBus, c[3],Phase[3], r3);
ResetableReg16(SD(coord,"aa"), CBus, c[4],Phase[3], r4);
ResetableReg16(SD(coord,"aa"), CBus, c[8],Phase[3], r8);
ResetableReg16(SD(coord,"aa"), CBus, c[9],Phase[3], r9);
ResetableReg16(SD(coord,"aa"), CBus, c[10],Phase[3], r10);
ResetableReg16(SD(coord,"aa"), CBus, c[11],Phase[3], r11);
ResetableReg16(SD(coord,"aa"), CBus, c[12],Phase[3], r12);
ResetableReg16(SD(coord,"aa"), CBus, c[13],Phase[3], r13);
ResetableReg16(SD(coord,"aa"), CBus, c[14],Phase[3], r14);
ResetableReg16(SD(coord,"aa"), CBus, c[15],Phase[3], r15);
*/

Register(SD(coord,"aa"),c[0], Phase[2],CBus, r0);
Register(SD(coord,"aa"),c[1], Phase[2],CBus, r1);
Register(SD(coord,"aa"),c[2], Phase[2],CBus, r2);
Register(SD(coord,"aa"),c[3], Phase[2],CBus, r3);
Register(SD(coord,"aa"),c[4], Phase[2],CBus, r4);
Register(SD(coord,"aa"),c[14], Phase[2],CBus, r14);
Register(SD(coord,"aa"),c[15], Phase[2],CBus, r15);
Register(SD(coord,"aa"),c[13], Phase[2],CBus, r13);
Register(SD(coord,"aa"),c[8], Phase[2],CBus, r8);
Register(SD(coord,"aa"),c[9], Phase[2],CBus, r9);
Register(SD(coord,"aa"),c[10], Phase[2],CBus, r10);
Register(SD(coord,"aa"),c[11], Phase[2],CBus, r11);
Register(SD(coord,"aa"),c[12], Phase[2],CBus, r12);

//Decoder(SD(coord,"aa"),CBus,(c,c,c,c), (r15,r14,r13,r12,r11,r10,r9,r8,r7,r6,r5,r4,r3,r2,r1,r0));


ALU16(SD(coord,"aa"),  AMux, BBus,(mir[28],mir[27]), ALU, N, Z);
SHIFTER16(SD(coord,"aa"), ALU, (mir[26],mir[25]), CBus);





Mux(SD(coord,"aa"), (mir[11],mir[10],mir[9],mir[8]), (R15,R14,R13,R12,R11,R10,R9,R8,R7,R6,R5,R4,R3,R2,R1,R0), ABus);
Mux(SD(coord,"aa"), (mir[15],mir[14],mir[13],mir[12]), (R15,R14,R13,R12,R11,R10,R9,R8,R7,R6,R5,R4,R3,R2,R1,R0), BBus);

Reg16(SD(coord,"aa"), ABus, Phase[0], ALatch);
Reg16(SD(coord,"aa"), BBus, Phase[0], BLatch);

Mux(SD(coord,"aa"), mir[31],(mbr,ALatch), AMux);




   /* ----------------------------------------------------------------------
      Write your DataPath ciruit here

      Make sure you use a component CompName as follows:

            CompName( SD(coord,"aa"),  ...., .... );
                      ^^^^^^^^^^^^^^
                      Use this coordinate for EVERY component (keep "aa")
      ---------------------------------------------------------------------- */



}

#include "Sim.h"

#include "basic.h"

void Four_Phase_Clock(const SD &coord,
                      const Signal &Reset, const Signal &Clk,
                      const Signal &Phase);
void ALU16(const SD &coord,
           const Signal &a, const Signal &b, const Signal &c, // c[1] c[0]
           const Signal &s, const Signal &N, const Signal &Z);
void SHIFTER16(const SD &coord,
               const Signal &a, const Signal &c, // c[1] c[0]
               const Signal &s);
void MIR( const SD &coord,
          const Signal & Addr /* 6 bits */,
          const Signal & mir  /* 32 bits */
        );

#include "datapath.h"

void simnet()
{

   Sig(addr,6);            // Address signals

   Sig(AMux, 1);           // Micro instruction signals
   Sig(CC, 2);
   Sig(ALU, 2);
   Sig(Shf, 2);
   Sig(MBR, 1);
   Sig(MAR, 1);
   Sig(RD, 1);
   Sig(WR, 1);
   Sig(EnC, 1);
   Sig(C, 4);
   Sig(B, 4);
   Sig(A, 4);
   Sig(Addr, 8);



   Sig( Reset, 1 );
   Sig( Clk, 1 );

   SigV(mbr, 16, 0b1100110011001100);  // SigV() = Sig() with initialization
   Sig( Phase, 4 );


   /* =====================================================================
      4 phase clock
      ===================================================================== */
   Switch( "jz", Reset, 'b', One);              // Controls for 4 phase clock
   Switch( "kz", Clk,   'a', Zero );   

   Four_Phase_Clock("kw-ky", Reset, Clk, Phase );

   Probe("ju", Phase[0]);
   Probe("jv", Phase[1]);
   Probe("jw", Phase[2]);
   Probe("jx", Phase[3]);


   /* =====================================================================
      MIR
      ===================================================================== */
   Switch( "ht", addr[5], '5', Zero );     // Controls to select instr in MIR
   Switch( "ht", addr[4], '4', Zero );   
   Switch( "ht", addr[3], '3', Zero );   
   Switch( "it", addr[2], '2', Zero );   
   Switch( "it", addr[1], '1', Zero );   
   Switch( "it", addr[0], '0', Zero );   

   MIR( "hu-iy", addr,
         (AMux, CC, ALU, Shf, MBR, MAR, RD, WR, EnC, C, B, A, Addr) );

   ProbeH("as", AMux);
   ProbeH("at-au", CC);
   ProbeH("av-aw", ALU);
   ProbeH("ax-ay", Shf);
   ProbeH("bv", MBR);
   ProbeH("bw", MAR);
   ProbeH("bx", RD);
   ProbeH("by", WR);
   ProbeH("ct", EnC);
   ProbeH("cv-cy", C);

   ProbeH("dv-dy", B);
   ProbeH("ev-ey", A);
   ProbeH("fs-fz", Addr);



   Sig( R0, 16 ); Sig( R1, 16 ); Sig( R2, 16 ); Sig( R3, 16 );
   Sig( R4, 16 ); Sig( R5, 16 ); Sig( R6, 16 ); Sig( R7, 16 );
   Sig( R8, 16 ); Sig( R9, 16 ); Sig( R10, 16 ); Sig( R11, 16 );
   Sig( R12, 16 ); Sig( R13, 16 ); Sig( R14, 16 ); Sig( R15, 16 );
   Sig( ABus, 16 ); Sig( BBus, 16 ); 
   Sig( A_Latch, 16 ); Sig( B_Latch, 16 ); 
   Sig( Amux, 16 );  // AMux is taken
   Sig( Alu, 16 );   // ALU  is taken
   Sig( C_bus, 16 ); // C    is taken
   Sig(N,1);
   Sig(Z,1);

   DataPath("ih-kk", 
      (AMux, CC, ALU, Shf, MBR, MAR, RD, WR, EnC, C, B, A, Addr),
      mbr, Phase, Reset,
      R0, R1, R2, R3, R4, R5, R6, R7, R8, R9, R10, R11, R12, R13, R14, R15,
      ABus, BBus, A_Latch, B_Latch, Amux, Alu, C_bus, N, Z);


   ProbeH("aa-ah", R0);
   ProbeH("ba-bh", R1);
   ProbeH("ca-ch", R2);
   ProbeH("da-dh", R3);
   ProbeH("ea-eh", R4);
   ProbeH("fa-fh", R5);
   ProbeH("ga-gh", R6);
   ProbeH("ha-hh", R7);

   ProbeH("aj-aq", R8);
   ProbeH("bj-bq", R9);
   ProbeH("cj-cq", R10);
   ProbeH("dj-dq", R11);
   ProbeH("ej-eq", R12);
   ProbeH("fj-fq", R13);
   ProbeH("gj-gq", R14);
   ProbeH("hj-hq", R15);


   ProbeH("lk-lr", ABus);
   ProbeH("lt-l{", BBus);

   ProbeH("ok-or", A_Latch);
   ProbeH("ot-o{", B_Latch);

   ProbeH("qa-qh", mbr);
   ProbeH("qk-qr", Amux);

   ProbeH("so-sv", Alu);
   ProbeH("sm", N);
   ProbeH("sm", Z);

   ProbeH("uo-uv", C_bus);
}

