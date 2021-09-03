void MoveStrings(vector<string>& s, vector<string>& d)
{
	for (auto c : s)
	{
		d.push_back(c);
	}
	s.clear();
}
