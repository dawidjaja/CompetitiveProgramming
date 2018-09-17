var
	ty,tx:array[0..100] of longint;
	msk,i,j,k,cu,ct,cs,cb,cek,n:longint;
begin
//reading
	readln(msk);
	for i:=1 to msk do
		begin
		read(tx[i]);
		end;
	for i:=1 to msk do
		begin
		read(ty[i]);
		end;
	n:=0;
//pengecekan
	for i:=-200 to 200 do
		begin
		for j:=-200 to 200 do
			begin
			cek:=0;
			cu:=0;
			ct:=0;
			cs:=0;
			cb:=0;
			for k:=1 to msk do
				begin
				if (tx[k]>i) and (ty[k]=j) then
					begin
					ct:=1;
					end;
				if (tx[k]<i) and (ty[k]=j) then
					begin
					cb:=1;
					end;
				if (tx[k]=i) and (ty[k]>j) then
					begin
					cu:=1;
					end;
				if (tx[k]=i) and (ty[k]<j) then
					begin
					cs:=1;
					end;
				end;
				begin
				if (cu=1) and (ct=1) and (cs=1) and (cb=1) then
					begin
					n:=n+1;
					end;
				end;
			end;
		end;
		writeln(n);
end.