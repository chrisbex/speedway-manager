class Motor
{
	public:
		Motor();
		~Motor();
		int GetSpeed() { return itsSpeed; };
		int GetStan() { return itsStan; };
		int GetSilnik() { return itsSilnik; };
		void SetSpeed(int value) { itsSpeed=value; };
		void SetStan(int value) { itsStan=value; };
		void SetSilnik(int value) { itsSilnik=value; };

	private:
		int itsSpeed;
		int itsStan;
		int itsSilnik;
		char *itsName;
};

Motor::Motor()
{
	itsSpeed=0;
	itsStan=0;
	itsSilnik=0;
	itsName=new char[7];
	itsName="No_Name";
};

Motor::~Motor()
{
	delete itsName;
};
