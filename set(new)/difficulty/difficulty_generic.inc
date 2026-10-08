	{any
		{translate_damage 5}		;// damage multiplier for blast-wave damage to humans
		{cover_hitchance 0.7}			;// the probability of hitting a soldier behind cover
		{cover_damage 0.8}			;// damage when protected by cover
		{translate_damage 4.0}		;// damage multiplier for blastwave damage to humans


		{cover_hitchance 0.7}			;// the probability of hitting a soldier behind cover
		{crawl_damage 1.00}			;// damage when in prone position

		{vehicle_burst 0.65}		;// increase bullet count in 1 burst for all vehicles (values < 1 reduce shots in burst)
		{cover_mgun_burst 1.12}		;// increase bullet count in 1 burst of soldier with mgun in horizontal cover
		{cover_mgun_delay 0.82}		;// decrease timeout between bursts of soldier with mgun in horizontal cover

		{recoil			0.25}			;// recoil multiplier for all machine guns
		{recoil_zoom	0.15}		;// recoil multiplier in zoom mode
		{vehicle_recoil 0}			;// recoil multiplier for all machine guns mounted on vehicles

		{cover_efficiency			;// IAEM add
			0		0.15
			1		0.25
			2		0.35
			5		0.45
			8		0.55
                        10              0.70
			15		0.75
			20		0.80
			25		0.85
		}

		;// Modifies human's distance from blast-wave center when calculating amount of energy that hits the human. 2.0 = double the distance. 
		{blast_crawl 3.00}			;// simply lying on the ground
		{blast_cover 10.00}			;// in cover from protected side
		{blast_crawl_prepared 6.00}	;// lying on the ground & waiting for explosion
		{blast_cover_prepared 8.00}	;// in cover not from protected side, but waiting for explosion
		{blast_squat 1.20}			;// on the knees

		{death_delay_min 300}		;// min bleeding out time in seconds
		{death_delay_max 400}		;// max bleeding out time in seconds

		{firing_timeout 1.07}		;// time out between bursts (modifier on FiringTimeout)
		{grenade_timeout 14}		;// time out between grenades (modifier on FiringTimeout)

		{ai_damage 1.0}				;// damage multiplier for AI humans against other AI humans, does not effect player controlled units
		{burst 1}					;// multiplier to number of bullets in burst from weapon settings
		{accuracy 0.97}				;// accuracy multiplier from weapon settings
		{health 1}					;// health multiplier from soldier settings
	}