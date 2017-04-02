#ifndef CUBIECUBE_H
#define CUBIECUBE_H
#include <string>

class CubieCube {
public:
	CubieCube();
	CubieCube(int, int, int, int);
	~CubieCube();
	CubieCube(const CubieCube&) = default;
	CubieCube& operator=(const CubieCube& cc) = default;
	bool operator==(const CubieCube& rhs) const;
	bool equalsCorn(CubieCube c) const;
	bool equalsEdge(CubieCube c) const;
private:
	CubieCube* temps;
	char ca[8];// = {0, 1, 2, 3, 4, 5, 6, 7};
    char ea[12];// = {0, 2, 4, 6, 8, 10, 12, 14, 16, 18, 20, 22};
public:

	void invCubieCube();
	static void CornMult(const CubieCube& a, const CubieCube& b,
		CubieCube& prod);
	static void EdgeMult(const CubieCube& a, const CubieCube& b,
		CubieCube& prod);

	// 16 symmetries generated by S_F2, S_U4 and S_LR2
	static CubieCube CubeSym[16];

	// 18 move cubes
	static CubieCube moveCube[18];

	static long moveCubeSym[18];
	static int firstMoveSym[48];

	static int preMove[9];

	static int SymInv[16];
	static int SymMult[16][16];
	static int SymMove[16][18];
	static int SymMultInv[16][16];
	static int Sym8Mult[8*8];
	static int Sym8Move[8*18];
	static int Sym8MultInv[8*8];
	static int SymMoveUD[16][10];

	// ClassIndexToRepresentantArrays
	static char FlipS2R[336];
	static char TwistS2R[324];
	static char EPermS2R[2768];

	/**
	 * Notice that Edge Perm Coordnate and Corner Perm Coordnate are the same symmetry structure.
	 * So their ClassIndexToRepresentantArray are the same.
	 * And when x is RawEdgePermCoordnate, y*16+k is SymEdgePermCoordnate, y*16+(k^e2c[k]) will
	 * be the SymCornerPermCoordnate of the State whose RawCornerPermCoordnate is x.
	 */
	static char e2c[16];

	static unsigned short MtoEPerm[40320];

	/**
	 * Raw-Coordnate to Sym-Coordnate, only for speeding up initializaion.
	 */
	static char FlipR2S[2048];// = new char[2048];
	static char TwistR2S[2048];// = new char[2187];
	static char EPermR2S[2048];// = new char[40320];
	static char FlipS2RF[336*8];

	static char SymStateTwist[324];
	static char SymStateFlip[336];
	static char SymStatePerm[2768];

	static CubieCube urf1;// = CubieCube(2531, 1373, 67026819, 1367);
	static CubieCube urf2;// = CubieCube(2089, 1906, 322752913, 2040);
	static char urfMove[6][18];

	static void CornConjugate(const CubieCube& a, int idx, CubieCube& b);
	static void EdgeConjugate(const CubieCube& a, int idx, CubieCube& b);
	void URFConjugate();

	int getFlip() const;
	void setFlip(int idx);
	int getFlipSym();
	int getTwist() const;
	void setTwist(int idx);

	int getTwistSym();

	int getUDSlice();

	void setUDSlice(int idx);
	int getU4Comb() const;
	int getD4Comb() const;
	int getCPerm() const;
	void setCPerm(int idx);
	int getCPermSym();
	int getEPerm() const;
	void setEPerm(int idx);
	int getEPermSym();
	int getMPerm() const;
	void setMPerm(int idx);
	int getCComb() const;
	void setCComb(int idx);
	int verify();

	long selfSymmetry();

	void setUDSliceFlip(int idx);

	int getUDSliceFlip() const;
	int getUDSliceFlipSym();

	static void initMove();

	std::string toString() const;

	static void initSym();

	static void initFlipSym2Raw();

	static void initTwistSym2Raw();

	static char Perm2Comb[2768];

	static void initPermSym2Raw();

	static void initUDSliceFlipSym2Raw();

	friend std::ostream& operator<< (std::ostream& o, const CubieCube& cc) {
		o << cc.toString();
		return o;
	}
};

#endif
