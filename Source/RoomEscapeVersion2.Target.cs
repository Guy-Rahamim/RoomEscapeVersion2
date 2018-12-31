// Fill out your copyright notice in the Description page of Project Settings.

using UnrealBuildTool;
using System.Collections.Generic;

public class RoomEscapeVersion2Target : TargetRules
{
	public RoomEscapeVersion2Target(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Game;

		ExtraModuleNames.AddRange( new string[] { "RoomEscapeVersion2" } );
	}
}
