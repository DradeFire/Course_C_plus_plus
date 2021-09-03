class ReversibleString {
	string str;
public:
	ReversibleString(string tmp_str)
	{
		str = tmp_str;
	}
	ReversibleString() {}
	void Reverse()
	{
		int Size = str.size();
		char tmp_ch;
		for (int i = Size / 2; i < Size; i++)
		{
			tmp_ch = str[i];
			str[i] = str[Size - 1 - i];
			str[Size - 1 - i] = tmp_ch;
		}
	}
	string ToString() const
	{
		return str;
	}
};
