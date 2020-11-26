@echo off
echo "Compiling..."
arduino-cli compile --upload
echo "Recording Data..."
C:\dev\csharp\spr\bin\Debug\netcoreapp3.1\spr -p COM3 -r
echo "Plotting Data..."
python PointPlotter.py output.txt
