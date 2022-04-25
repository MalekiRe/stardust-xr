#pragma once

#include <string>

#define MULTILINE_STR(...) #__VA_ARGS__

std::string skKeymapString = MULTILINE_STR(
xkb_keymap {

default xkb_keycodes "basic" {
	minimum = 8;
	maximum = 255;

	<backspace> = 8;
	<tab> = 9;
	<return> = 13;
	<shift> = 16;
	<ctrl> = 17;
	<alt> = 18;
	<caps_lock> = 20;
	<esc> = 27;
	<space> = 32;
	<end> = 35;
	<home> = 36;
	<left> = 37;
	<right> = 39;
	<up> = 38;
	<down> = 40;
	<page_up> = 33;
	<page_down> = 34;
	<printscreen> = 42;
	<key_insert> = 45;
	<del> = 46;

	<0> = 48;
	<1> = 49;
	<2> = 50;
	<3> = 51;
	<4> = 52;
	<5> = 53;
	<6> = 54;
	<7> = 55;
	<8> = 56;
	<9> = 57;

	<a> = 65;
	<b> = 66;
	<c> = 67;
	<d> = 68;
	<e> = 69;
	<f> = 70;
	<g> = 71;
	<h> = 72;
	<i> = 73;
	<j> = 74;
	<k> = 75;
	<l> = 76;
	<m> = 77;
	<n> = 78;
	<o> = 79;
	<p> = 80;
	<q> = 81;
	<r> = 82;
	<s> = 83;
	<t> = 84;
	<u> = 85;
	<v> = 86;
	<w> = 87;
	<x> = 88;
	<y> = 89;
	<z> = 90;

	<num0> = 96;
	<num1> = 97;
	<num2> = 98;
	<num3> = 99;
	<num4> = 100;
	<num5> = 101;
	<num6> = 102;
	<num7> = 103;
	<num8> = 104;
	<num9> = 105;

	<f1> = 112;
	<f2> = 113;
	<f3> = 114;
	<f4> = 115;
	<f5> = 116;
	<f6> = 117;
	<f7> = 118;
	<f8> = 119;
	<f9> = 120;
	<f10> = 121;
	<f11> = 122;
	<f12> = 123;

	<comma> = 188;
	<period> = 190;
	<slash_fwd> = 191;
	<slash_back> = 220;
	<semicolon> = 186;
	<apostrophe> = 222;
	<bracket_open> = 219;
	<bracket_close> = 221;
	<minus> = 189;
	<equals> = 187;
	<backtick> = 192;
	<lcmd> = 91;
	<rcmd> = 92;
	<multiply> = 106;
	<add> = 107;
	<subtract> = 109;
	<decimal> = 110;
	<divide> = 111;
};

partial default xkb_types "basic" {
	virtual_modifiers Alt;

	type "ONE_LEVEL" {
		modifiers= none;
		level_name[1]= "Any";
	};
	type "TWO_LEVEL" {
		modifiers= Shift;
		map[Shift]= 2;
		level_name[1]= "Base";
		level_name[2]= "Shift";
	};
	type "ALPHABETIC" {
		modifiers= Shift+Lock;
		map[Shift]= 2;
		map[Lock]= 2;
		level_name[1]= "Base";
		level_name[2]= "Caps";
	};
	type "SHIFT+ALT" {
		modifiers= Shift+Alt;
		map[Shift+Alt]= 2;
		level_name[1]= "Base";
		level_name[2]= "Shift+Alt";
	};
	type "PC_CONTROL_LEVEL2" {
		modifiers= Control;
		map[Control]= 2;
		level_name[1]= "Base";
		level_name[2]= "Control";
	};
};

partial default xkb_compatibility "basic" {
	interpret.useModMapMods= AnyLevel;
	interpret.repeat= False;

	interpret ISO_Level2_Latch+Exactly(Shift) {
		useModMapMods=level1;
		action= LatchMods(modifiers=Shift,clearLocks,latchToLock);
	};
	interpret Caps_Lock+AnyOfOrNone(all) {
		action= LockMods(modifiers=Lock);
	};
	indicator "Caps Lock" {
		whichModState= locked;
		modifiers= Lock;
	};
};

default xkb_symbols "basic" {
	name[Group1]="English (US)";
		key <backspace>     { [ BackSpace, BackSpace ] };
		key <tab>        	{ [ Tab, ISO_Left_Tab ] };
		key <return>        { [ Return ] };
		key <shift>        	{ [ Shift_L ] };
		key <shift>        	{ [ Shift_R ] };
		key <ctrl>        	{ [ Control_L ] };
		key <ctrl>        	{ [ Control_R ] };
		key <alt>        	{ [ Alt_L ] };
		key <alt>        	{ [ Alt_R ] };
		key <caps_lock>     { [ Caps_Lock ] };
		key <esc>        	{ [ Escape ] };
		key <space>        	{ [ space ] };
		key <end>        	{ [ End ] };
		key <home>        	{ [ Home ] };
		key <left>        	{ [ Left ] };
		key <right>        	{ [ Right ] };
		key <up>        	{ [ Up ] };
		key <down>        	{ [ Down ] };
		key <page_up>       { [ Page_Up ] };
		key <page_down>     { [ Page_Down ] };
		key <printscreen>   { [ Print ] };
		key <key_insert>    { [ Insert ] };
		key <del>        	{ [ Delete ] };

		key <1>             { [ 1, exclam ] };
		key <2>             { [ 2, at ] };
		key <3>             { [ 3, numbersign ] };
		key <4>             { [ 4, dollar ] };
		key <5>             { [ 5, percent ] };
		key <6>             { [ 6, asciicircum ] };
		key <7>             { [ 7, ampersand ] };
		key <8>             { [ 8, asterisk ] };
		key <9>             { [ 9, parenleft ] };
		key <0>             { [ 0, parenright ] };

		key <a>             { [ a, A ] };
		key <b>             { [ b, B ] };
		key <c>             { [ c, C ] };
		key <d>             { [ d, D ] };
		key <e>             { [ e, E ] };
		key <f>             { [ f, F ] };
		key <g>             { [ g, G ] };
		key <h>             { [ h, H ] };
		key <i>             { [ i, I ] };
		key <j>             { [ j, J ] };
		key <k>             { [ k, K ] };
		key <l>             { [ l, L ] };
		key <m>             { [ m, M ] };
		key <n>             { [ n, N ] };
		key <o>             { [ o, O ] };
		key <p>             { [ p, P ] };
		key <q>             { [ q, Q ] };
		key <r>             { [ r, R ] };
		key <s>             { [ s, S ] };
		key <t>             { [ t, T ] };
		key <u>             { [ u, U ] };
		key <v>             { [ v, V ] };
		key <w>             { [ w, W ] };
		key <x>             { [ x, X ] };
		key <y>             { [ y, Y ] };
		key <z>             { [ z, Z ] };

		key <num0>        	{ [ KP_0 ] };
		key <num1>        	{ [ KP_1 ] };
		key <num2>        	{ [ KP_2 ] };
		key <num3>        	{ [ KP_3 ] };
		key <num4>        	{ [ KP_4 ] };
		key <num5>        	{ [ KP_5 ] };
		key <num6>        	{ [ KP_6 ] };
		key <num7>        	{ [ KP_7 ] };
		key <num8>        	{ [ KP_8 ] };
		key <num9>        	{ [ KP_9 ] };

		key <f1>        	{ [ F1 ] };
		key <f2>        	{ [ F2 ] };
		key <f3>        	{ [ F3 ] };
		key <f4>        	{ [ F4 ] };
		key <f5>        	{ [ F5 ] };
		key <f6>        	{ [ F6 ] };
		key <f7>        	{ [ F7 ] };
		key <f8>        	{ [ F8 ] };
		key <f9>        	{ [ F9 ] };
		key <f10>        	{ [ F10 ] };
		key <f11>        	{ [ F11 ] };
		key <f12>        	{ [ F12 ] };

		key <comma>        	{ [ comma, less ] };
		key <period>        { [ period, greater ] };
		key <slash_fwd>     { [ slash, question ] };
		key <slash_back>    { [ backslash, bar ] };
		key <semicolon>     { [ semicolon, colon ] };
		key <apostrophe>    { [ apostrophe ] };
		key <bracket_open>  { [ bracketleft, braceleft ] };
		key <bracket_close> { [ bracketright, braceright ] };
		key <minus>			{ [ minus, underscore ] };
		key <equals>        { [ equal, plus ] };
		key <backtick>      { [ grave, asciitilde ] };
		key <lcmd>        	{ [ Super_L ] };
		key <rcmd>        	{ [ Super_R ] };
		key <multiply>      { [ KP_Multiply ] };
		key <add>        	{ [ KP_Add ] };
		key <subtract>      { [ KP_Subtract ] };
		key <decimal>       { [ KP_Decimal ] };
		key <divide>        { [ KP_Divide ] };

		modifier_map Shift { <shift> };
		modifier_map Lock { <caps_lock> };
		modifier_map Control { <caps_lock> };
		modifier_map Mod1 { <alt> };
		modifier_map Mod4 { <lcmd>, <rcmd> };
};

};

);

#undef MULTILINE_STR
