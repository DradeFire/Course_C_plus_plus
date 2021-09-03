vector<string> PalindromFilter(vector<string> words, int minLength)
{
	vector<string> str;
	for (auto s : words)
	{
		int kek = 0;
		if (s.size() < minLength)
			continue;
		for (int a = 0, b = s.size() - 1;a <= b; a++, b--)
		{
			if (s[a] != s[b])
			{
				kek = 1;
				break;
			}
		}
		if (kek)
			continue;
		str.push_back(s);
	}
	return str;

}
