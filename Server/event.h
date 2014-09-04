#pragma once

class gameuser_live;

class gameuser_idle;
class gameuser_move;
class gameuser_skill1;
class gameuser_skill2;

class gameuser_condition;// �����̻� , stat ����,

class gameuser_dead;
class gameuser_common;



namespace sc = boost::statechart;

enum skilltype{ skill1, skill2 };
struct evtick : sc::event < evtick >
{
	evtick(float arg_tick) :m_tick(arg_tick){}
	float m_tick;
};

struct evmove : sc::event < evmove > {};
template< skilltype _skilltype >
struct evskill : sc::event < evskill<_skilltype> > {};
struct evjump : sc::event < evjump > {};
struct evland : sc::event < evland > {};


struct evmakedata : sc::event < evmakedata > {};

struct evpacketdatalist : sc::event < evpacketdatalist > {
	packet_encoder* m_packet;
	evpacketdatalist(packet_encoder* arg_packet)
		:m_packet(arg_packet)
	{

	}
};

struct evpacketinfolist : sc::event < evpacketinfolist > {
	packet_encoder* m_packet;
	evpacketinfolist(packet_encoder* arg_packet)
		:m_packet(arg_packet)
	{

	}
};

struct evaddgameobject : sc::event < evaddgameobject > 
{
	gameobject* m_gameobject;
	evaddgameobject(gameobject* arg_gameobject)
		:m_gameobject(arg_gameobject)
	{
		
	}
};


struct evdeletegameobject : sc::event < evdeletegameobject >
{
	gameobject* m_gameobject;
	evdeletegameobject(gameobject* arg_gameobject)
		:m_gameobject(arg_gameobject)
	{

	}
};