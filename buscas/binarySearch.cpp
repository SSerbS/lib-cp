ll bs(vector<int> &arr, ll x) {
    ll low = 0;
    ll high = arr.size() - 1;
    while (low <= high) {
        ll mid = low + (high - low) / 2;

        if (arr[mid] == x)
            return mid;
        if (arr[mid] < x)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}


bool f(int m){
  //checa se m resolve o problema.
  //Caso “f” consiga ser resolvida em tempo linear, a complexidade do código se torna O(N×Log(r)).
}

ll bsOnAnswer(){
  ll l = 1;
  ll r = 1e18;

  while(l <= r){
      ll m = (l + r) / 2;
      if(f(m, a, t)){
        ans = m;
        r = m - 1;
      }
    else{
      l = m + 1;
    }
  }

}
