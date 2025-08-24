/* tools/lib/cmdline.c */
# define fallthrough                    do {} while (0) 

/* include/linux/hwmon-sysfs.h */
#define SENSOR_DEVICE_ATTR_RO(_name, _func, _index)             \
        SENSOR_DEVICE_ATTR(_name, 0444, _func##_show, NULL, _index)
   

#define SENSOR_DEVICE_ATTR_RW(_name, _func, _index)             \
        SENSOR_DEVICE_ATTR(_name, 0644, _func##_show, _func##_store, _index)


/* include/linux/interrupt.h */

#define from_tasklet(var, callback_tasklet, tasklet_fieldname)  \
        container_of(callback_tasklet, typeof(*var), tasklet_fieldname)                         0xc0

//******************************
/* include/linux/lockdep.h */

#define lockdep_is_held(lock)           lock_is_held(&(lock)->dep_map)

/* include/linux/rcupdate.h */

/**
 * rcu_replace_pointer() - replace an RCU pointer, returning its old value
 * @rcu_ptr: RCU pointer, whose old value is returned
 * @ptr: regular pointer
 * @c: the lockdep conditions under which the dereference will take place
 *
 * Perform a replacement, where @rcu_ptr is an RCU-annotated
 * pointer and @c is the lockdep argument that is passed to the
 * rcu_dereference_protected() call used to read that pointer.  The old
 * value of @rcu_ptr is returned, and @rcu_ptr is set to @ptr.
 */
#define rcu_replace_pointer(rcu_ptr, ptr, c)                            \
({                                                                      \
        typeof(ptr) __tmp = rcu_dereference_protected((rcu_ptr), (c));  \
        rcu_assign_pointer((rcu_ptr), (ptr));                           \
        __tmp;                                                          \
})

//******************************
/* include/linux/timekeeping.h */

static inline u64 ktime_get_boottime_ns(void)
{
        return ktime_to_ns(ktime_get_boottime());
}

//******************************
/* include/net/netlink.h */

/**
 * nla_parse_deprecated - Parse a stream of attributes into a tb buffer
 * @tb: destination array with maxtype+1 elements
 * @maxtype: maximum attribute type to be expected
 * @head: head of attribute stream
 * @len: length of attribute stream
 * @policy: validation policy
 * @extack: extended ACK pointer
 *
 * Parses a stream of attributes and stores a pointer to each attribute in
 * the tb array accessible via the attribute type. Attributes with a type
 * exceeding maxtype will be ignored and attributes from the policy are not
 * always strictly validated (only for new attributes).
 *
 * Returns: 0 on success or a negative error code.
 */
static inline int nla_parse_deprecated(struct nlattr **tb, int maxtype, const struct nlattr *head, int len, const struct nla_policy *policy, struct netlink_ext_ack *extack)
{
        return nla_parse(tb, maxtype, head, len, policy, extack);
}

//******************************
//PROBABLY SHOULD DISABLE EVERYTHING BELOW
/* include/linux/ieee80211.h */

#define IEEE80211_HE_MAC_CAP3_MAX_AMPDU_LEN_EXP_MASK            	0x18
#define IEEE80211_HE_PHY_CAP8_DCM_MAX_RU_MASK  				0xc0	

//******************************
/* include/net/cfg80211.h */
/**
 * struct survey_info - channel survey response
 *
 * @channel: the channel this survey record reports, may be %NULL for a single
 *	record to report global statistics
 * @filled: bitflag of flags from &enum survey_info_flags
 * @noise: channel noise in dBm. This and all following fields are
 *	optional
 * @time: amount of time in ms the radio was turn on (on the channel)
 * @time_busy: amount of time the primary channel was sensed busy
 * @time_ext_busy: amount of time the extension channel was sensed busy
 * @time_rx: amount of time the radio spent receiving data
 * @time_tx: amount of time the radio spent transmitting data
 * @time_scan: amount of time the radio spent for scanning
 * @time_bss_rx: amount of time the radio spent receiving data on a local BSS
 *
 * Used by dump_survey() to report back per-channel survey information.
 *
 * This structure can later be expanded with things like
 * channel duty cycle etc.
 */
struct survey_info_linux_4_9_compat {
	struct ieee80211_channel *channel;
	u64 time;
	u64 time_busy;
	u64 time_ext_busy;
	u64 time_rx;
	u64 time_tx;
	u64 time_scan;
	u64 time_bss_rx;
	u32 filled;
	s8 noise;
};

//******************************
/* include/net/mac80211.h */

#define IEEE80211_AMPDU_TX_START_IMMEDIATE 1

enum mac80211_tx_info_flags_linux4_9_compat {

	IEEE80211_TX_CTL_HW_80211_ENCAP		= BIT(14)

};