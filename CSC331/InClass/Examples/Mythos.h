class Mythos
{
	public:
		Mythos(std::string, int, bool);
		void printMythos();
		void setName(std::string);
		void setSize(int);
		void setHasScales(bool);

	private:
		std::string name;
		int size;
		bool hasScales;
};

