#pragma once
#define _CRT_SECURE_NO_WARNINGS

#include <string>
#include <vector>
#include <fstream>
#include <algorithm>
#include <iostream>
#include <Windows.h>
#include <io.h>

#define IsOperation(k) (k < 12)

using namespace std;

enum TypeOfLex
{
	LAdd,
	LSub,
	LMul,
	LDiv,
	LMod,
	LEqu,
	LNotEqu,
	LGreate,
	LLess,
	LNot,
	LAnd,
	LOr,

	LBegProg,
	LProgram,
	LProgramName,
	LStart,
	LData,
	LVarType,
	LIdentifier,
	LEnd,

	LScan,
	LPrint,

	LIf,
	LElse,
	LFor,

	LNewValue,

	LDLine,
	LLBraket,
	LRBraket,
	LNumber,
	LSeparator,
	LComma,
	LEOF,
	LLComentar,
	LRComentar,
	LUnknown
};

struct LexAndName
{
	TypeOfLex type;
	std::string name;
};

//DATA
typedef struct Lexem
{
	string name;
	int value;
	int line;
	TypeOfLex type;
}Lexema;

typedef struct L
{
	vector<Lexema> LexTable;			//Таблиця лексем

	vector<string> IdTable;		//Таблиця ідентифікаторів
	string ftype = "m89";
	string TName = "xxxxx";
	vector<LexAndName> LexName =
	{
		{LAdd,"+"},
		{LSub,"-"},
		{LMul,"*" },
		{LDiv,"Div"},
		{LMod,"Mod"},
		{LEqu,"Eq"},
		{LNotEqu,"Noteq"},
		{LGreate,"Gr"},
		{LLess,"Less"},
		{LNot,"!!"},
		{LAnd,"&&"},
		{LOr,"||"},

		{LBegProg,""},
		{LProgram,"Name"},
		{LProgramName,""},
		{LStart,"Body"},
		{LData,"Data"},
		{LVarType,"Longint"},
		{LIdentifier,""},
		{LEnd,"End"},

		{LScan,"Read"},
		{LPrint,"Write"},

		{LIf,"If"},
		{LElse,"Else"},
		{LFor,"For"},

		{LNewValue,"<<"},

		{LLBraket,"("},
		{LRBraket,")"},
		{LDLine,"_"},
		{LNumber,""},
		{LSeparator,";"},
		{LComma,","},
		{LLComentar,"??"},
		{LRComentar,"??"},
		{LEOF,"EndFile"}
	};

	bool IsPresentInput,					//Ознаки присутності операторів
		IsPresentOutput,
		IsPresentMod,
		IsPresentAnd,
		IsPresentOr,
		IsPresentNot,
		IsPresentEqu,
		IsPresentGreate,
		IsPresentLess,
		IsPresentDiv;

	bool EnableProgN = 1, PosLStart = 0;

	int numberErrors;

	std::string InputFileName;
	std::string OutputFileName;
}DataType;

bool directory_exists(const std::string& directory);