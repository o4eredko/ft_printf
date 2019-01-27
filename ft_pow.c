/*Header*/

double		ft_pow(double nbr, int pow)
{
	double res;

	res = 1;
	while (pow)
	{
		res = pow < 0 ? res / nbr : res * nbr;
		pow += pow < 0 ? 1 : -1;
	}
	return (res);
}