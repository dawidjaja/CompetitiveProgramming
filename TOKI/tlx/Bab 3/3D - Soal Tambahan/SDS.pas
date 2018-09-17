var
	list:array[0..100000] of real;
	msk,i:longint;
	min,max,mean,tot,sds:real;
begin
	readln(msk);
	for i:=1 to msk do
		begin
		readln(list[i]);
		end;
	min:=list[1];
	for i:=1 to msk do
		begin
		if list[i]<min then
			begin
			min:=list[i];
			end;
		end;
	max:=list[1];
	for i:=1 to msk do
		begin
		if list[i]>max then
			begin
			max:=list[i];
			end;
		end;
	tot:=0;
	for i:=1 to msk do
		begin
		tot:=tot+list[i];
		end;
	mean:=tot/msk;
	sds:=0;
	for i:=1 to msk do
		begin
		sds:=sds+(list[i]*list[i]);
		end;
	sds:=sqrt((sds-(msk*mean*mean))/(msk-1));
	writeln(min:0:2,' ',max:0:2,' ',mean:0:2,' ',sds:0:2);
end.