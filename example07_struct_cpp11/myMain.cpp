struct mystruct
{
	float one_;
	char two_;
	int three_;
};

unsigned long long myMain()
{
	mystruct foo;
	foo.one_=2.3;
	foo.two_='F';
	foo.three_=100;
	return foo.three_;
}
