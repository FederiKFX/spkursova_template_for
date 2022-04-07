#include "Analizer.h"
#include "ErrorsCheck.h"
#include "Generator.h"

FILE* InF, * OutF, * ErrorF;

#define Lex(K) LexName[K].name.c_str()
string a = "a", a2 = "a2", b = "b", c = "c", c1 = "c1", c2 = "c2", x = "x", y = "y";
string name = "prog", endV = "_6";
void PrintProg1(FILE* f, DataType* Data)
{
	vector<LexAndName> LexName = Data->LexName;
	std::sort(LexName.begin(), LexName.end(), []
	(const LexAndName& first, const LexAndName& second) {return first.type < second.type; });
	fprintf(f, "%sProg1%s\n", Lex(LLComentar), Lex(LRComentar));
	fprintf(f, "%s%s", Lex(LBegProg), Lex(LProgram));
	if (Data->EnableProgN)
	{
		fprintf(f, " %s1;\n", name.c_str());
	}
	else
	{
		fputs("\n", f);
	}
	if (!Data->PosLStart)
	{
		fprintf(f, "%s\n", Lex(LStart));
	}
	fprintf(f, "%s %s%s %s,%s,%s,%s;\n", Lex(LData), Lex(LVarType), endV.c_str(), a.c_str(), b.c_str(), x.c_str(), y.c_str());
	if (Data->PosLStart)
	{
		fprintf(f, "%s\n", Lex(LStart));
	}
	fprintf(f, "%s(%s);\n", Lex(LScan), a.c_str());
	fprintf(f, "%s(%s);\n", Lex(LScan), b.c_str());
	fprintf(f, "%s(%s %s %s);\n", Lex(LPrint), a.c_str(), Lex(LAdd), b.c_str());
	fprintf(f, "%s(%s %s %s);\n", Lex(LPrint), a.c_str(), Lex(LSub), b.c_str());
	fprintf(f, "%s(%s %s %s);\n", Lex(LPrint), a.c_str(), Lex(LMul), b.c_str());
	fprintf(f, "%s(%s %s %s);\n", Lex(LPrint), a.c_str(), Lex(LDiv), b.c_str());
	fprintf(f, "%s(%s %s %s);\n", Lex(LPrint), a.c_str(), Lex(LMod), b.c_str());
	fprintf(f, "%s%s(%s %s %s) %s 10 %s (%s %s %s) %s 10;\n", x.c_str(), Lex(LNewValue), a.c_str(), Lex(LSub), b.c_str(), Lex(LMul), Lex(LAdd), a.c_str(), Lex(LAdd), b.c_str(), Lex(LDiv));
	fprintf(f, "%s%s%s %s (%s %s 10);\n", y.c_str(), Lex(LNewValue), x.c_str(), Lex(LAdd), x.c_str(), Lex(LMod));
	fprintf(f, "%s(%s);\n", Lex(LPrint), x.c_str());
	fprintf(f, "%s(%s);\n", Lex(LPrint), y.c_str());
	fprintf(f, "%s", Lex(LEnd));
}

void PrintProg2(FILE* f, DataType* Data)
{
	vector<LexAndName> LexName = Data->LexName;
	std::sort(LexName.begin(), LexName.end(), []
	(const LexAndName& first, const LexAndName& second) {return first.type < second.type; });
	fprintf(f, "%sProg2%s\n", Lex(LLComentar), Lex(LRComentar));
	fprintf(f, "%s%s", Lex(LBegProg), Lex(LProgram));
	if (Data->EnableProgN)
	{
		fprintf(f, " %s2;\n", name.c_str());
	}
	else
	{
		fputs("\n", f);
	}
	if (!Data->PosLStart)
	{
		fprintf(f, "%s\n", Lex(LStart));
	}
	fprintf(f, "%s %s%s %s,%s,%s;\n", Lex(LData), Lex(LVarType), endV.c_str(), a.c_str(), b.c_str(), c.c_str());
	if (Data->PosLStart)
	{
		fprintf(f, "%s\n", Lex(LStart));
	}
	fprintf(f, "%s(%s);\n", Lex(LScan), a.c_str());
	fprintf(f, "%s(%s);\n", Lex(LScan), b.c_str());
	fprintf(f, "%s(%s);\n", Lex(LScan), c.c_str());
	fprintf(f, "%s(%s %s %s)\n", Lex(LIf), a.c_str(), Lex(LGreate), b.c_str());
	fprintf(f, "%s\n", Lex(LStart));
	fprintf(f, "\t%s(%s %s %s)\n", Lex(LIf), a.c_str(), Lex(LLess), c.c_str());
	fprintf(f, "\t%s\n", Lex(LStart));
	fprintf(f, "\t\t%s(%s);\n", Lex(LPrint), c.c_str());
	fprintf(f, "\t%s\n", Lex(LElse));
	fprintf(f, "\t\t%s(%s);\n", Lex(LPrint), a.c_str());
	fprintf(f, "\t%s\n", Lex(LEnd));
	fprintf(f, "%s\n", Lex(LElse));
	fprintf(f, "\t%s(%s %s %s)\n", Lex(LIf), b.c_str(), Lex(LLess), c.c_str());
	fprintf(f, "\t%s\n", Lex(LStart));
	fprintf(f, "\t\t%s(%s);\n", Lex(LPrint), c.c_str());
	fprintf(f, "\t%s\n", Lex(LElse));
	fprintf(f, "\t\t%s(%s);\n", Lex(LPrint), b.c_str());
	fprintf(f, "\t%s\n", Lex(LEnd));
	fprintf(f, "%s\n", Lex(LEnd));

	fprintf(f, "%s((%s %s %s) %s (%s %s %s) %s (%s %s %s))\n", Lex(LIf), a.c_str(), Lex(LEqu), b.c_str(), Lex(LAnd), a.c_str(), Lex(LEqu), c.c_str(), Lex(LAnd), b.c_str(), Lex(LEqu), c.c_str());
	fprintf(f, "%s\n", Lex(LStart));
	fprintf(f, "\t%s(1);\n", Lex(LPrint));
	fprintf(f, "%s\n", Lex(LElse));
	fprintf(f, "\t%s(0);\n", Lex(LPrint));
	fprintf(f, "%s\n", Lex(LEnd));

	fprintf(f, "%s((%s %s 0) %s (%s %s 0) %s (%s %s 0))\n", Lex(LIf), a.c_str(), Lex(LLess), Lex(LOr), b.c_str(), Lex(LLess), Lex(LOr), c.c_str(), Lex(LLess));
	fprintf(f, "%s\n", Lex(LStart));
	fprintf(f, "\t%s(%s 1);\n", Lex(LPrint), Lex(LSub));
	fprintf(f, "%s\n", Lex(LElse));
	fprintf(f, "\t%s(0);\n", Lex(LPrint));
	fprintf(f, "%s\n", Lex(LEnd));

	fprintf(f, "%s(%s(%s %s (%s %s %s)))\n", Lex(LIf), Lex(LNot), a.c_str(), Lex(LLess), b.c_str(), Lex(LAdd), c.c_str());
	fprintf(f, "%s\n", Lex(LStart));
	fprintf(f, "\t%s(10);\n", Lex(LPrint));
	fprintf(f, "%s\n", Lex(LElse));
	fprintf(f, "\t%s(0);\n", Lex(LPrint));
	fprintf(f, "%s\n", Lex(LEnd));

	fprintf(f, "%s", Lex(LEnd));
}

void PrintProg3(FILE* f, DataType* Data)
{
	vector<LexAndName> LexName = Data->LexName;
	std::sort(LexName.begin(), LexName.end(), []
	(const LexAndName& first, const LexAndName& second) {return first.type < second.type; });
	fprintf(f, "%sProg3%s\n", Lex(LLComentar), Lex(LRComentar));
	fprintf(f, "%s%s", Lex(LBegProg), Lex(LProgram));
	if (Data->EnableProgN)
	{
		fprintf(f, " %s3;\n", name.c_str());
	}
	else
	{
		fputs("\n", f);
	}
	if (!Data->PosLStart)
	{
		fprintf(f, "%s\n", Lex(LStart));
	}
	fprintf(f, "%s %s%s %s,%s,%s,%s,%s,%s;\n", Lex(LData), Lex(LVarType), endV.c_str(), a.c_str(), a2.c_str(), b.c_str(), x.c_str(), c1.c_str(), c2.c_str());
	if (Data->PosLStart)
	{
		fprintf(f, "%s\n", Lex(LStart));
	}
	fprintf(f, "%s(%s);\n", Lex(LScan), a.c_str());
	fprintf(f, "%s(%s);\n", Lex(LScan), b.c_str());
	fprintf(f, "%s(%s%s%s; %s(%s %s %s); %s%s%s %s 1)\n", Lex(LFor), a2.c_str(), Lex(LNewValue), a.c_str(), Lex(LNot), a2.c_str(), Lex(LGreate), b.c_str(), a2.c_str(), Lex(LNewValue), a2.c_str(), Lex(LAdd));
	fprintf(f, "%s\n", Lex(LStart));
	fprintf(f, "\t%s(%s %s %s);\n", Lex(LPrint), a2.c_str(), Lex(LMul), a2.c_str());
	fprintf(f, "%s\n", Lex(LEnd));
	fprintf(f, "%s%s0;\n", x.c_str(), Lex(LNewValue));
	fprintf(f, "%s(%s%s0; %s %s %s; %s%s%s %s 1)\n", Lex(LFor), c1.c_str(), Lex(LNewValue), c1.c_str(), Lex(LLess), a.c_str(), c1.c_str(), Lex(LNewValue), c1.c_str(), Lex(LAdd));
	fprintf(f, "%s\n", Lex(LStart));
	fprintf(f, "\t%s(%s%s0; %s %s %s; %s%s%s %s 1)\n", Lex(LFor), c2.c_str(), Lex(LNewValue), c2.c_str(), Lex(LLess), b.c_str(), c2.c_str(), Lex(LNewValue), c2.c_str(), Lex(LAdd));
	fprintf(f, "\t%s\n", Lex(LStart));
	fprintf(f, "\t\t%s%s%s %s 1;\n", x.c_str(), Lex(LNewValue), x.c_str(), Lex(LAdd));
	fprintf(f, "\t%s\n", Lex(LEnd));
	fprintf(f, "%s\n", Lex(LEnd));
	fprintf(f, "%s(%s);\n", Lex(LPrint), x.c_str());
	fprintf(f, "%s", Lex(LEnd));
}

int main(int argc, std::string* argv)
{
	//SetConsoleOutputCP(CP_UTF8);
	//setvbuf(stdout, nullptr, _IOFBF, 1000);
	DataType* Data = new DataType;
	Analizer A(Data);
	ErrorsCheck E(Data);
	Generator G(Data);
	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
	printf("TRANSLATOR (%s -> ASSEMBLER)\n", Data->ftype.c_str());
	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");

	// Checking the number of arguments to be passed from the command line
	if (argc != 2)
	{
		printf("Input file name\n");
		std::cin >> Data->InputFileName;
	}
	else
	{
		// Obtaining and formation names of incoming and outgoing files
		Data->InputFileName = argv->c_str();
	}

	if ((InF = fopen(Data->InputFileName.c_str(), "r")) == 0)
	{
		printf("Error: Can not open file: %s\n", Data->InputFileName.c_str());
		if ((OutF = fopen(std::string("prog1." + Data->ftype).c_str(), "w")) != 0)
		{
			PrintProg1(OutF, Data);
			fclose(OutF);
		}
		if ((OutF = fopen(std::string("prog2." + Data->ftype).c_str(), "w")) != 0)
		{
			PrintProg2(OutF, Data);
			fclose(OutF);
		}
		if ((OutF = fopen(std::string("prog3." + Data->ftype).c_str(), "w")) != 0)
		{
			PrintProg3(OutF, Data);
			fclose(OutF);
		}
		system("pause");
		exit(1);
	}

	char temp[4] = { '\0' };

	Data->InputFileName.copy(temp, 3, Data->InputFileName.size() - 3);

	if (std::string(temp) != Data->ftype)
	{
		printf("Error: Invalid file type: %s\n", Data->InputFileName.c_str());
		system("pause");
		exit(1);
	}

	printf("Start translating file: %s\n", Data->InputFileName.c_str());
	int k = Data->InputFileName.size();
	while (k > 0)
	{
		if (Data->InputFileName[k] == '\\')
		{
			k++;
			break;
		}
		k--;
	}
	Data->OutputFileName = Data->InputFileName;
	Data->OutputFileName.erase(Data->InputFileName.size() - 4, Data->InputFileName.size());
	Data->OutputFileName.erase(0, k);

	printf("Output file: %s\n", std::string(Data->OutputFileName + ".asm").c_str());
	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");

	// Breaking into tokens and printing into file
	printf("Breaking into lexems are starting...\n");
	A.AnalisisLexems(InF);
	A.PrintLexemsInFile();
	printf("Breaking into lexems completed. There are %d lexems.\nReport file: lexems.txt\n", Data->LexTable.size());
	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");


	printf("Error checking are starting...\n");
	Data->numberErrors = E.ErrorChecking();
	printf("Error checking is complete. There is(are) %d errors.\nReport file: errors.txt\n", Data->numberErrors);
	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");

	// If there are no errors, go to a translation stage
	if (Data->numberErrors != 0)
	{
		printf("Translation can not be continued. Errors were found. Please correct the errors and try again.\n");
	}
	else
	{
		if ((OutF = fopen(std::string(Data->OutputFileName + ".asm").c_str(), "w")) == 0)
		{
			printf("Error: Can not create file: %s\n", std::string(Data->OutputFileName + ".asm").c_str());
			system("pause");
			exit(1);
		}
		printf("Code generation is starting...\n");
		G.GenerateCode(OutF);
		printf("Code generation is finish.\n");
		fclose(OutF);
		printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
		if (directory_exists("masm32"))
		{
			system(std::string("masm32\\bin\\ml /c /coff " + Data->OutputFileName + ".asm").c_str());
			system(std::string("masm32\\bin\\Link /SUBSYSTEM:WINDOWS " + Data->OutputFileName + ".obj").c_str());
			//system(std::string("del " + std::string(Data->OutputFileName) + ".obj").c_str());
		}
		else
		{
			printf("WARNING!\n");
			printf("Can't compile asm file, because masm32 doesn't exist.\n");
		}

		printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
		printf("Done!\n");
	}
	system("pause");
	return 0;
}