BOOL is_int(string str)
{
	int str_len = strlen(str);
	
	if(str_len > 0) {
		int key;

		for(key=0; key<=str_len; key++) {
			if(str_len == key) {
				return TRUE;
			} else {
				if(str[key]<'0' || str[key]>'9') {
					return FALSE;
				}
			}
		}
	} else {
		return FALSE;
	}
}
