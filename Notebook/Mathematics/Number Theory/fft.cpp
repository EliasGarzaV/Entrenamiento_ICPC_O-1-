#include "../template.cpp"

/* look up table */
void 
twiddle(int n, double w[])
{
	double arg;
	double aw;
	int i;
	const double pi =  3.1415926;

	aw = 2.0 * pi / ((double ) n);

	for (i = 0 ; i < n / 2 ; i++)  {
		arg = aw * ((double) i);
		w[i * 2 + 0] = cos ( arg );
		w[i * 2 + 1] = sin ( arg );
	}
	return;
}

/* FFT */
void
FFT(double *x, double *y, int n, double w[])
{

	int m, i, j, k, nbits;
   	double tempx, tempy;
	m = 0;
	i = n;
	while (i > 0) {
		i /= 2;
		m++;
	}
	m -= 1;

	/* bit reversal */
	nbits = n >> 1;
	j = 0;
	for (i = 0 ; i < n - 1 ; i++)  {
		if (i < j) {
			tempx = x[i];
		 	tempy = y[i];
			x[i] = x[j];
		 	y[i] = y[j];
		 	x[j] = tempx;
		 	y[j] = tempy;
	      	}
	      	k = nbits;
	      	while (k <= j) {
			j -= k;
			k >>= 1;
		}
	      	j += k;
	   }
	   /* butterfly operations */
	int mj, term_i, stride_i, mi, j2, count2;
	double u1, u2, t1, t2;
	mj = 1;
	stride_i = n / ( 4 * mj );
	for (k = 0 ; k < m ; k++) {
		mi = 2 * mj;	
		term_i = n / mi;
		for (i = 0 ; i < term_i ; i++) {
			count2 = 0;
			for (j = i * mi ; count2 < mj ; j++ , count2++) {
				j %= ( n - 1 );
				j2 = ( j + mj );
				
				int temp = count2 * n / mi;
				u1 = w[temp * 2 + 0];
				u2 = - w[temp * 2 + 1];

				t1 = u1 * x[j2] - u2 * y[j2];
		    		t2 = u1 * y[j2] + u2 * x[j2];
				x[j2] = x[j] - t1;
				y[j2] = y[j] - t2;
				x[j] += t1;
				y[j] += t2;
			}
		}
		stride_i /= 2;
		mj *= 2;
	}  
	return;
}