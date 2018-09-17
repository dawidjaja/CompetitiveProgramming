var
	list:array[-10000..10000] of string;
	msk,i,pd,pb:longint;
	cmd:string;
begin
	readln(msk);
	pd:=0;
	pb:=1;
	for i:=1 to msk do
		begin
		readln(cmd);
		if copy(cmd,1,4)='push' then
			begin
			if copy(cmd,6,4)='back' then
				begin
				list[pb]:=copy(cmd,11,length(cmd)-10);
				pb:=pb+1;
				end;
			if copy(cmd,6,5)='front' then
				begin
				list[pd]:=copy(cmd,12,length(cmd)-11);
				pd:=pd-1;
				end;
			end;
		if copy(cmd,1,3)='pop' then
			begin
			if pb-pd>1 then
				begin
				if copy(cmd,5,4)='back' then
					begin
					pb:=pb-1;
					end;
				if copy(cmd,5,5)='front' then
					begin
					pd:=pd+1;
					end;
				end;
			end;
		end;
	for i:=pd+1 to pb-1 do
		begin
		writeln(list[i]);
		end;
end.