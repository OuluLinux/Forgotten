
rm *.cxx *.hxx *.C *.H; fog -t4 -I../../src -DPOSIX=1 -DCPU64=1 -global Global -nobanner -f ComTest.mfog

