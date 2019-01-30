def strict(m: Int): Int = {
	def str(k: Int)(n: Int): Int = {
		if ( k == 0 ) {
			if ( n == 0 ) { return 1 }
			else { return 0 }
		}
		else {
			if ( k > n ) { return str(n)(n) }
			else { str(k-1)(n) + str(k-1)(n-k) }
		}
	}
	str(m)(m)
}