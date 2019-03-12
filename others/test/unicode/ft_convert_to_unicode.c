unsigned int	ft_convert_to_unicode(unsigned int nb)
{
	unsigned int	c;
	unsigned int	tmp;

	if (nb < 2048)
	{
		c = 49280;
		c |= nb % 64;
		tmp = nb / 64;
		tmp <<= 8;
		c |= tmp;
	}
	else if (nb <= 65535)
	{
		c = 14712960;
		c |= nb % 64;
		tmp = nb / 4096;
		tmp <<= 8;
		tmp |= nb % 4096 / 64;
		tmp <<= 8;
		c |= tmp;
	}
	else if (nb <= 2097152)
	{
		c = 3766517888;
		c |= nb % 64;
		tmp = nb / 262144;
		tmp <<= 8;
		tmp |= nb % 262144 / 4096;
		tmp <<= 8;
		tmp |= nb % 4096 / 64;
		tmp <<= 8;
		c |= tmp;
	}
	return (c);
}
