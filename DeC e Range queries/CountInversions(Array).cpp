vector<int> a;
ll countAndMerge(int l, int m, int r){

    int n1 = m - l + 1, n2 = r - m;

    vector<int> left(n1), right(n2);

    for(int i = 0; i < n1; i++) left[i] = a[i + l];
    for(int j = 0; j < n2; j++) right[j] = a[m + 1 + j];

    ll res = 0;
    int i = 0, j = 0, k = l;

    while (i < n1 && j < n2)
    {
        if (left[i] <= right[j]) a[k++]= left[i++];
        else {
            a[k++] = right[j++];
            res +=  (n1 - i);
        }
    }


    while (i < n1) a[k++] = left[i++];
    while (j < n2) a[k++] = right[j++];


    return res;
    
}

ll countInv (int l, int r){
    ll res = 0;

    if(l < r){
        int m = (r + l) / 2;    

        res += countInv(l, m);
        res += countInv(m + 1, r);


        res += countAndMerge(l, m, r);
    }

    return res;
}

void solve(){
    a = vector<int>();
    int n; cin >> n;

    for (int i = 0; i < n; i++){
        int b; cin >> b;
        a.push_back(b);
    }
    cout << countInv(0, n - 1) << "\n";
}
