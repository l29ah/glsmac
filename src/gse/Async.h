#pragma once

#include <map>
#include <vector>

#include "common/Common.h"

#include "Value.h"
#include "Types.h"

namespace gse {

namespace context {
class Context;
}

CLASS( Async, common::Class )

	typedef size_t timer_id_t;

	void Iterate();

	const timer_id_t StartTimer( const size_t ms, const gse::Value& f, gse::context::Context* const ctx, const gse::si_t& si );
	const bool StopTimer( const timer_id_t id );
	void StopTimers();

	void ProcessAndExit();

private:

	struct timer_t {
		size_t ms;
		gse::Value callable;
		gse::context::Context* ctx;
		gse::si_t si;
	};

	typedef std::map< uint64_t, std::map< timer_id_t, timer_t > > timers_t;
	timers_t m_timers = {};
	std::map< timer_id_t, uint64_t > m_timers_ms = {};

	const uint64_t Now() const;
	void ValidateMs( const int64_t ms, context::Context* ctx, const si_t& call_si ) const;
	void ProcessTimers( const timers_t::iterator& it );
};

}
