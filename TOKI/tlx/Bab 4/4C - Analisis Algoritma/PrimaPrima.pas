var
	prime,cek:array[0..10000] of longint;
	num,i,a,b,n,x,y,j,ud,akar,k,tes:longint;
	tu,wa:string;
	ril:real;
begin
//reading
	readln(a,b);
//initialize
	for i:=1 to 10000 do
		begin
		cek[i]:=0;
		end;
	n:=1;
	for i:=2 to 10000 do
		begin
		if cek[i]=0 then
			begin
			prime[n]:=i;
			for j:=1 to (10000 div i) do
				begin
				cek[j*i]:=1;
				end;
			n:=n+1;
			end;
		end;
	tes:=0;
	ud:=0;
	for i:=1 to n-1 do
		begin
		if ud=0 then
			begin
			if prime[i]>=a then
				begin
				x:=i;
				ud:=1;
				end;
			end;
		if prime[i]<=b then
			begin
			y:=i;
			end;
		end;
	for i:=x to y do
		begin
		for j:=x to y do
			begin
			str(prime[i],tu);
			str(prime[j],wa);
			val(tu+wa,num);
			ril:=sqrt(num);
			akar:=trunc(ril);
			ud:=0;
			for k:=2 to akar do
				begin
				if ((num div k)*k)=num then
					begin
					ud:=1;
					end;
				end;
			if ud=0 then
				begin
				writeln(prime[i],' ',prime[j]);
				tes:=1;
				end;
			end;
		end;
	if tes=0 then
		begin
		writeln('TIDAK ADA');
		end;
end.