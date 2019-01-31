def odd(m: Int): Int = {
	def od(k: Int)(n: Int): Int = {
		if ( k == 0 ) {
			if ( n == 0 ) { return 1 }
			else { return 0 }
		}
		else {
			if ( k > n ) { return od(n)(n) }
			else {
				if (k%2 == 0) { return od(k-1)(n) }
				else { return od(k-1)(n)+od(k)(n-k) }
			}
		}
	}
	od(m)(m)
}