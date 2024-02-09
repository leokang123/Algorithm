    int N; cin >> N ;
    num = N;
    for (int i = 1 ; i <= N ; i++) cin >> arr[i];
    makeHeap(num);
    heapSort();
    showArr(N);