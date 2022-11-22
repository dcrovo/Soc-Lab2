/* Quartus Prime Version 21.1.1 Build 850 06/23/2022 SJ Lite Edition */
JedecChain;
	FileRevision(JESD32A);
	DefaultMfr(6E);

	P ActionCode(Ign)
		Device PartName(SOCVHPS) MfrSpec(OpMask(0));
	P ActionCode(Cfg)
		Device PartName(5CSEMA5F31) Path("/home/danielcrovo/Documents/Daniel/01.Study/01.MScEE/02.Semester2/SoC/Taller2_3/output_files/") File("nios2_p3.sof") MfrSpec(OpMask(1));

ChainEnd;

AlteraBegin;
	ChainType(JTAG);
AlteraEnd;
