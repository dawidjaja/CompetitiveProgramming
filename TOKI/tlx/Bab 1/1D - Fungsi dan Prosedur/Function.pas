var
	bil:longint;
function Valid(n: integer): boolean;
begin
    Valid := (n >= 0) and (n <= 10);
end;
function Faktorial (n:integer):longint;
begin
    if (n = 0) then
		begin
        Faktorial := 1;
		end
    else
		begin
        Faktorial := n * Faktorial (n - 1);
		end;
end;
begin
    readln(bil);
    if (Valid(bil)) then
		begin
        writeln(Faktorial(bil));
		end
		else
		begin
        writeln('ditolak');
		end
end.
