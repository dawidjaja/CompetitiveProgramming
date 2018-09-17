var
	list:array [0..1000000] of longint;
	msk,i,a,klmpk,kcl,akh:longint;
	Z:text;
begin
	assign(Z,'cowjog.in');
	reset(Z);
	readln(Z,msk);
	for i:=1 to msk do
		begin
		readln(Z,a,list[i]);
		end;
	close(Z);
	kcl:=list[1];
	akh:=0;
	klmpk:=0;
	while akh+1<=msk do
		begin
		for i:=akh+1 to msk do
			begin
			if list[i]<kcl then
				begin
				kcl:=list[i];
				end;
			end;
		for i:=akh+1 to msk do
			begin
			if list[i]=kcl then
				begin
				klmpk:=klmpk+1;
				akh:=i;
				end;
			end;
		end;
	assign(Z,'cowjog.out');
	rewrite(Z);
	writeln(Z,klmpk);
	close(Z);
end.