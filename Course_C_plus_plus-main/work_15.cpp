void Reverse(vector<int>& v)
{
	int tmp;
	for (int i = 0; i < (v.size() / 2); i++)
	{
		tmp = v[i];
		v[i] = v[v.size() - 1 - i];
		v[v.size() - 1 - i] = tmp;
	}
}

vector<int> Reversed(const vector<int>& v)
{
	vector<int> kek = v;
	Reverse(kek);
	return kek;
}
